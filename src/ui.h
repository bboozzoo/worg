#ifndef __UI_H__
#define __UI_H__
#include <gtkmm.h>
#include <boost/shared_ptr.hpp>
#include "ui-popup-menu.h"

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
        void init_gfx();
        void init_popup_menu();
        void on_popup_menu_quit();
        void quit();

        static ui_sptr_t                m_instance;
        Gtk::Main                       m_kit;
        Glib::RefPtr<Gtk::StatusIcon>   m_icon;
        Gtk::Menu *                     m_popup_menu;
};

#endif /* __UI_H__ */

