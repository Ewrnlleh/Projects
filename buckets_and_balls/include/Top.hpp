

#ifndef TOP_HPP
#define TOP_HPP

class Top{
	private:
		Top* topAdres;
		char topHarf;
		
	public:
		void setTopAdres(Top*);
		Top* getTopAdres();
		void setTopHarf(char);
		char getTopHarf();
};

#endif