#ifndef ApplicationUI_H_
#define ApplicationUI_H_

#include <QObject>

namespace bb
{
    namespace cascades
    {
        class Application;
    }
}

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }
private:
};

#endif /* ApplicationUI_H_ */
