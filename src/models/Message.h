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

private:
    QString m_text;
	MessageRole m_role = MessageRole::User;
	QDateTime m_timestamp;
};