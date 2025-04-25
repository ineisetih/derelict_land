#ifndef DIRECTOR_H
#define DIRECTOR_H

class Director {
 private:
  int story_points = 0;

 public:
  int GetStoryPoints() const;
  void SetStoryPoints(int points);
};

#endif
