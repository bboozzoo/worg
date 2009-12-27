#include "activity-model.h"
#include "log.h"
#include "error.h"

ActivityTypeModel::ActivityTypeModel()
    : m_id(0), m_name("")
{
}

ActivityTypeModel::~ActivityTypeModel()
{
}

void
ActivityTypeModel::set_name(Glib::ustring & name)
{
    LOG(1, "ATM setting name: " << name);
    m_name = name;
}

void 
ActivityTypeModel::set_id(unsigned int id) 
{
    LOG(1, "AT setting id: " << id);
    m_id = id;
}

Glib::ustring
ActivityTypeModel::get_name()
{
    return m_name;
}

unsigned int
ActivityTypeModel::get_id()
{
    return m_id;
}




ActivityModel::ActivityModel()
    : m_id(0), m_start_time(), m_end_time()
{
}

ActivityModel::~ActivityModel()
{
}

void
ActivityModel::set_start(Glib::TimeVal start)
{
    LOG(1, "AM setting start time: " << start.as_iso8601());
    m_start_time = start;
}

void
ActivityModel::set_end(Glib::TimeVal end)
{
    LOG(1, "AM setting end time: " << end.as_iso8601());
    m_end_time = end;
}

Glib::TimeVal
ActivityModel::get_start()
{
    return m_start_time;
}

Glib::TimeVal
ActivityModel::get_end()
{
    return m_end_time;
}

void
ActivityModel::add_type(atmodel_sptr_t type)
{
    LOG(1, "AM adding type: " << type->get_name() << " to activity ID: " << m_id);
    m_types.push_back(type);
}

std::list<atmodel_sptr_t> &
ActivityModel::get_types()
{
    return m_types;
}

void
ActivityModel::set_id(unsigned int id)
{
    LOG(1, "AM setting id: " << id);
    m_id = id;
}

unsigned int
ActivityModel::get_id()
{
    return m_id;
}

Glib::TimeVal
ActivityModel::get_duration()
{
    if (!m_start_time.valid())
        throw Error("AM start time invalid", ERR_HERE);

    if (!m_end_time.valid()) 
    {
        LOG(0, "AM activity: " << m_id << " still in progress?");
        return Glib::TimeVal(); 
    }

    Glib::TimeVal end = m_end_time;
    end -= m_start_time;
    LOG(1, "AM start time: " << m_start_time.as_iso8601() << " end time: " << m_end_time.as_iso8601() << " duration: " << end.as_iso8601());
    return end;
}

