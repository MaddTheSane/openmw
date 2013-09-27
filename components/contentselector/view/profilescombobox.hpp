#ifndef PROFILESCOMBOBOX_HPP
#define PROFILESCOMBOBOX_HPP

#include <QComboBox>
#include <QStylePainter>
class QString;
class QRegExpValidator;

namespace ContentSelectorView
{
    class ProfilesComboBox : public QComboBox
    {
        Q_OBJECT
    public:
        explicit ProfilesComboBox(QWidget *parent = 0);
        void setEditEnabled(bool editable);
        void setPlaceholderText (const QString &text);

    signals:
        void profileChanged(const QString &previous, const QString &current);
        void profileRenamed(const QString &oldName, const QString &newName);

    private slots:
        void slotEditingFinished();
        void slotIndexChanged(int index);
        void slotTextChanged(const QString &text);

    private:
        QString mOldProfile;
        QString mPlaceholderText;
        QRegExpValidator *mValidator;

    protected:
        void paintEvent(QPaintEvent *);
    };
}

#endif // PROFILESCOMBOBOX_HPP