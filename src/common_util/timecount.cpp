#include "timecount.h"
#include "timeutil.h"
#include "strfmt.h"
#include "inner/logger.h"

namespace cutl
{
    timecount::timecount(const std::string &func_name)
        : func_name_(func_name)
    {
        start_time_ = clocktime(time_unit::microsecond);
    }

    timecount::~timecount()
    {
        auto end_time = clocktime(time_unit::microsecond);
        auto duration = end_time - start_time_;
        auto text = "[timecount] " + func_name_ + " used " + fmt_timeduration_us(duration);
        CUTL_LOGGER.info("", text);
    }
} // namespace