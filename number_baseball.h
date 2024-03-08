#ifndef NUMBER_BASEBALL_H_
#define NUMBER_BASEBALL_H_

class number_baseball{
	int num[3];
	int count = 10;
	int score;
public:
	number_baseball(void);
	bool Catch(void) const;
	bool playball(void);
	int ret_num(void) {return num[0]*100 + num[1] * 10 + num[2];}
	int ret_score(void) {return score;}
};

#endif
