#pragma once

#include "Menu.h"


class dislikeMenu: public Menu
{
public:
	
	    dislikeMenu	(const std::string& title, Application * app);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;

	private:
		List<Game*> games;

	};



	


