#ifndef __EXIT_H__
#define __EXIT_H__

#include "Commands.h"
#include "Base.h"

class Exit : public Commands {
	public:
		Exit();
		virtual bool execute();
};
#endif
