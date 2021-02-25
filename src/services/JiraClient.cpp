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
    file.setFileName(":/services/credentials/assets/credentials.json");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error reading resource file" << "\n";
        return;
    }

    QByteArray buffer = file.readAll();
    file.close();

    QJsonDocument document{ QJsonDocument::fromJson(buffer) };
    auto jiraCreds = document["jira"];
    m_ClientID = jiraCreds["client_id"].toString();
    m_ClientSecret = jiraCreds["client_secret"].toString();
    m_Scope = jiraCreds["scope"].toString();

    qDebug() << m_ClientID << "\n"
             << m_ClientSecret << "\n"
             << m_Scope << "\n";
}

void JiraClient::setupAuth() {
    init();

    m_Auth.setReplyHandler(&m_ReplyHandler);
    m_Auth.setClientIdentifier(m_ClientID);
    m_Auth.setClientIdentifierSharedKey(m_ClientSecret);
    m_Auth.setScope(m_Scope);

    connect(&m_Auth, &QOAuth2AuthorizationCodeFlow::granted, [=]() {
        emit authenticated();
        qDebug() << m_Auth.token() << "\n";
    });

    m_Auth.setModifyParametersFunction([=](const QAbstractOAuth::Stage stage, QVariantMap* params) {
        if (stage == QAbstractOAuth::Stage::RequestingAuthorization) {
            params->insert("prompt", "consent");
            params->insert("audience", "api.atlassian.com");
        }
    });

    connect(&m_Auth, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
}
