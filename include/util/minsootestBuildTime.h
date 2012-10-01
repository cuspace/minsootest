#ifndef D_minsootestBuildTime_H
#define D_minsootestBuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  minsootestBuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class minsootestBuildTime
  {
  public:
    explicit minsootestBuildTime();
    virtual ~minsootestBuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    minsootestBuildTime(const minsootestBuildTime&);
    minsootestBuildTime& operator=(const minsootestBuildTime&);

  };

#endif  // D_minsootestBuildTime_H
