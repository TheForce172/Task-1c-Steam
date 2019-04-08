#pragma once

#include "Menu.h"
#include "ListT.h"


class dislikeMenu: public Menu
{
public:
	
	    dislikeMenu	(const std::string& title, Application * app, List<Game*> games);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;

	private:
		List<Game*> games;

	};



	


