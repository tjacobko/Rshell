#ifndef __AMPERSAND_H__
#define __AMPERSAND_H__

class Ampersand : public Base {
	public:
		Ampersand();
		Ampersand(Base* lhs, Base* rhs);

		virtual bool execute();	
};
#endif
