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
        void init_gfx();
        void init_popup_menu();
        void on_tray_icon_popup(guint button, guint32 time);
        void on_tray_icon_quit();
        void on_tray_icon_position(int & x, int & y, bool & push_in);
        void quit();

        static ui_sptr_t                m_instance;
        Gtk::Main                       m_kit;
        Glib::RefPtr<Gtk::StatusIcon>   m_icon;
        Gtk::Menu *                     m_popup_menu;
};

#endif /* __UI_H__ */

