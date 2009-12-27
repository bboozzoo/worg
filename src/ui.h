#ifndef __UI_H__
#define __UI_H__
#include <gtkmm.h>
#include <boost/shared_ptr.hpp>

class UI;
typedef boost::shared_ptr<UI> ui_sptr_t;
class UI
{
    public:
        ~UI();
        static void init(int argc, char ** argv);
        static void finish();
        static ui_sptr_t instance();
        void run();
    private:
        UI(int argc, char ** argv);

        static ui_sptr_t   m_instance;
        Gtk::Main   m_kit;
};
#endif /* __UI_H__ */
