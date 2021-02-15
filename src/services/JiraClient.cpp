#include <QtGui>
#include "JiraClient.h"

QString JiraClient::s_AuthUrl = "https://auth.atlassian.com/authorize";
QString JiraClient::s_TokenUrl = "https://auth.atlassian.com/oauth/token";

JiraClient::JiraClient(QObject* parent):
    QObject(parent),
    m_ReplyHandler(1337, this),
    m_Auth(QUrl(s_AuthUrl), QUrl(s_TokenUrl), new QNetworkAccessManager{ this }, this)
{
    setupAuth();
}

void JiraClient::authorize() {
    m_Auth.grant();
}

void JiraClient::init() {
    QFile file;

    #ifdef QT_DEBUG
        QString subpath("debug");
    #else
        QString subpath("release");
    #endif

    file.setFileName(QString("%0/%1/assets/credentials.json").arg(QDir::currentPath()).arg(subpath));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray buffer = file.readAll();
    file.close();
    QJsonDocument document{ QJsonDocument::fromJson(buffer) };
    auto jiraCreds = document["jira"];
    m_ClientID = jiraCreds["client_id"].toString();
    m_ClientSecret = jiraCreds["client_secret"].toString();
    m_Scope = jiraCreds["scope"].toString();
}

void JiraClient::setupAuth() {
    init();

    m_Auth.setReplyHandler(&m_ReplyHandler);
    m_Auth.setClientIdentifier(m_ClientID);
    m_Auth.setClientIdentifierSharedKey(m_ClientSecret);
    m_Auth.setScope("read:jira-user write:jira-work read:jira-work");

    connect(&m_Auth, &QOAuth2AuthorizationCodeFlow::statusChanged, [=](const QAbstractOAuth::Status& status) {
        if (status == QAbstractOAuth::Status::Granted) {
            emit authenticated();
            qDebug() << m_Auth.token() << "\n";
        }
    });

    m_Auth.setModifyParametersFunction([=](const QAbstractOAuth::Stage stage, QVariantMap* params) {
        if (stage == QAbstractOAuth::Stage::RequestingAuthorization) {
            params->insert("prompt", "consent");
            params->insert("audience", "api.atlassian.com");
        }
    });

    connect(&m_Auth, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
}
