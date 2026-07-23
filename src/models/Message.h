#pragma

#include <QString>
#include <QDateTime>

enum class MessageRole
{
    User,
    Assistant,
    System
};

class Message
{
public:
    Message();

    QString Text() const;

    void SetText(const QString& text);

    MessageRole Role() const;
	void SetRole(MessageRole role);

    QDateTime Timestamp() const;

    void SetThinking(bool isThinking);
    bool IsThinking() const;

    bool m_isThinking = false;

    bool IsUser() const;

    bool IsAssistant() const;
private:
    QString m_text;
	MessageRole m_role = MessageRole::User;
	QDateTime m_timestamp;
};