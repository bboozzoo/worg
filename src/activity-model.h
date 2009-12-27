#ifndef __ACTIVITY_MODEL_H__
#define __ACTIVITY_MODEL_H__
#include <boost/shared_ptr.hpp>
#include <glibmm.h>
#include <list>

class ActivityTypeModel;
typedef boost::shared_ptr<ActivityTypeModel> atmodel_sptr_t;
class ActivityTypeModel
{
    public:
        ActivityTypeModel();
        ~ActivityTypeModel();
        virtual void set_name(Glib::ustring & name);
        virtual Glib::ustring get_name();
        virtual unsigned int get_id();
        virtual void set_id(unsigned int);
    private:
        unsigned int    m_id;
        Glib::ustring   m_name;
};

class ActivityModel;
typedef boost::shared_ptr<ActivityModel> amodel_sptr_t;
class ActivityModel 
{
    public:
        ActivityModel();
        ~ActivityModel();
        virtual void set_start(Glib::TimeVal);
        virtual void set_end(Glib::TimeVal);
#if 0
        virtual void set_types(std::list<Glib::ustring>);
#endif
        virtual Glib::TimeVal get_start();
        virtual Glib::TimeVal get_end();
        virtual Glib::TimeVal get_duration();
        virtual std::list<atmodel_sptr_t> & get_types();
        virtual void add_type(atmodel_sptr_t type);
        virtual unsigned int get_id();
        virtual void set_id(unsigned int);
    private:
        unsigned int    m_id;
        Glib::TimeVal   m_start_time;
        Glib::TimeVal   m_end_time;
        std::list<atmodel_sptr_t>   m_types;
};

#endif /* __ACTIVITY_MODEL_H__ */
