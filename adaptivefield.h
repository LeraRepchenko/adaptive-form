#ifndef ADAPTIVEFIELD_H
#define ADAPTIVEFIELD_H

#include <QLineEdit>
#include <QPlainTextEdit>
#include <QSizePolicy>

class QResizeEvent;

// QLineEdit, который логирует изменение размера и позволяет менять политику на лету.
// Q_OBJECT НЕ нужен, потому что resizeEvent — обычный виртуальный метод C++.
class AdaptiveLineEdit : public QLineEdit
{
public:
    explicit AdaptiveLineEdit(const QString &label, QWidget *parent = nullptr);
    void setHorizontalPolicy(QSizePolicy::Policy hp);
    void setVerticalPolicy(QSizePolicy::Policy vp);
    QString label() const { return m_label; }

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QString m_label;
};

// QPlainTextEdit с теми же возможностями.
class AdaptiveTextEdit : public QPlainTextEdit
{
public:
    explicit AdaptiveTextEdit(const QString &label, QWidget *parent = nullptr);
    void setHorizontalPolicy(QSizePolicy::Policy hp);
    void setVerticalPolicy(QSizePolicy::Policy vp);
    QString label() const { return m_label; }

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QString m_label;
};

#endif // ADAPTIVEFIELD_H