#ifndef VIRTUALKICKER_HPP
#define VIRTUALKICKER_HPP

#include "VirtualKickerWindow.hpp"
#include "TableControllerMock.hpp"

class VirtualKicker {

public:
	static const int WINDOW_SIZE_X = 1024;
	static const int WINDOW_SIZE_Y = 768;

	static TableControllerMock* getMockTableController() {
		vkw = new VirtualKickerWindow();
		tcm = new TableControllerMock(true, true, false, false);

		tcm->setKickerWindow(vkw);
		vkw->setTableController(tcm);

		vkw->setFixedSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
		vkw->show();

		return tcm;
	}

	static TableControllerImpl* getTableController(bool keeper, bool defense, bool midfield, bool offense) {
		vkw = new VirtualKickerWindow();
		tci = new TableControllerImpl(keeper, defense, midfield, offense);

		vkw->setTableController(tci);

		vkw->setFixedSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
		vkw->show();

		return tci;
	}

private:
	static VirtualKickerWindow* vkw;
	static TableControllerMock* tcm;
	static TableControllerImpl* tci;

};

VirtualKickerWindow* VirtualKicker::vkw;
TableControllerImpl* VirtualKicker::tci;
TableControllerMock* VirtualKicker::tcm;

#endif /* VIRTUALKICKER_HPP */

