#ifndef __UI_POPUP_MENU_H__
#define __UI_POPUP_MENU_H__
#include <boost/shared_ptr.hpp>
#include <gtkmm.h>

class UIPopupMenu;
typedef boost::shared_ptr<UIPopupMenu> ui_popmenu_sptr_t;
class UIPopupMenu 
{
    public:
        ~UIPopupMenu();
/*        static void init();*/
        static void init(Glib::RefPtr<Gtk::StatusIcon> icon);
        static void finish();
        static ui_popmenu_sptr_t instance();
        Gtk::Menu * menu();
        sigc::signal<void> signal_quit();
    private:
        UIPopupMenu();
        void on_menu_quit();
        void on_menu_popup(guint button, guint32 time);
        void on_menu_position(int & x, int & y, bool & push_in);

        static ui_popmenu_sptr_t        m_instance;
        Glib::RefPtr<Gtk::Builder>      m_ui_builder;
        Gtk::Menu *                     m_popup_menu;
        Glib::RefPtr<Gtk::StatusIcon>   m_parent_icon;
        sigc::signal<void>              m_signal_quit; /* connect to quit menu item */
};

#endif /* __UI_POPUP_MENU_H__ */
