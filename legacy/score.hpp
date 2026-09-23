#ifndef  SCORE_H
#define  SCORE_H
 
#include  "common.hpp"

class TBogScore;

class TBogScore : public IStaticText
{
   IFont myFont;
   IString sScore;
   int score_value;
   
   public:
      TBogScore(unsigned long id,
                IWindow* parent,
                IWindow* owner);
      ~TBogScore();
      void setScore(int);            // pass method wordlength and figure
                                     // out score
      void calcScore(int);
      void displayScore();
      void clearScore();
};

#endif
