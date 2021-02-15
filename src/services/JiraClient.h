#ifndef JIRACLIENT_H
#define JIRACLIENT_H

#include <QtNetworkAuth>
#include <QOAuth2AuthorizationCodeFlow>

class JiraClient : public QObject
{
    Q_OBJECT
public:
    JiraClient(QObject* parent);

    void authorize();

private:
    QString m_ClientID;
    QString m_ClientSecret;
    QString m_Scope;
    static QString s_AuthUrl;
    static QString s_TokenUrl;
    static QString s_UserAgent;

    QOAuthHttpServerReplyHandler m_ReplyHandler;
    QOAuth2AuthorizationCodeFlow m_Auth;

signals:
    void authenticated();

private:
    void init();
    void setupAuth();
};

#endif // JIRACLIENT_H
