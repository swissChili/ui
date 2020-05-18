#include <window.h>
#include <widgets/common.h>
#include <layouts/layout.h>

class MyWindow : public Ui::Window
{
public:
	MyWindow()
		: Ui::Window("My Window", 400, 400)
		, vlayout(new Ui::VLayout())
		, greenRect(new Ui::Rectangle(Ui::Color{0, 255, 100}))
		, blueRect(new Ui::Rectangle(Ui::Color{0, 10, 255}))
	{
		vlayout->add(greenRect);
		vlayout->add(blueRect);
		setChild(vlayout);
	}

	~MyWindow()
	{
		delete greenRect;
		delete blueRect;
		delete vlayout;
	}

private:
	Ui::VLayout *vlayout;
	Ui::Rectangle *greenRect;
	Ui::Rectangle *blueRect;
};

int main()
{
	MyWindow().show();
}
