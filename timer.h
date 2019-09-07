#pragma once

namespace std
{
  template<class unit>
  class timer
  {
    unit interval;
    bool ticking;
  public:
    timer(unit interval) : interval(interval)
    { 
      ticking = true;
    }

    void start()
    {
      ticking = true;
    }

    void stop()
    {
      ticking = false;
    }

    template<class cb, class ...vargs>
    void on_tick(cb callback, vargs... args)
    {
      while (true)
      {
        if (ticking)
        {
          callback(forward<vargs>(args)...);
          this_thread::sleep_for(interval);
        }
      }
    }
  };
}
