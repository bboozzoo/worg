#ifndef __ACTIVITY_MODEL_H__
#define __ACTIVITY_MODEL_H__
#include <glibmm.h>

class ActivityModel 
{
    public:
        ActivityModel();
        ~ActivityModel();
        virtual set_start(Glib::TimeVal) = 0;
        virtual set_end(Glib::TimeVal) = 0;
        virtual set_types(std::list<Glib::ustring>) = 0;
        virtual Glib::TimeVal get_start() = 0;
        virtual Glib::TimeVal get_end() = 0;
        virtual Glib::TimeVal get_duration() = 0;
        virtual std::list<Glib::ustring> get_types() = 0;

};

#endif /* __ACTIVITY_MODEL_H__ */
