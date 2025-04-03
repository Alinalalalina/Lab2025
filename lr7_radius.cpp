class Circle : public point
{
protected:
	int Radius;

public:
	Circle(int XN = 0, int YN = 0, int R = 0, int Color = 0) : Point(XN, YN, Color), Radius(R) {}

	void Show() override
	{
		setcolor(Color);
		setfillstyle(SOLID_FILL, Color);
		pieslice(X, Y, 0, 360, Radius);
	}

	void Hide() override
	{
		setcolor(getbkcolor());
		setfillstyle(SOLID_FILL, getbkcolor());
		pieslice(X, Y, 0, 360, Radius);
	}

	void ChangeSector(int startAngle, int endAngle)
	{
		Hide();
		setcolor(Color);
		setfillstyle(SOLID_FILL, Color);
		pieslice(X, Y, startAngle, endAngle, Radius);
	}

	void ChangeColor(int newColor)
	{
		Color = newColor;
		Show();
	}
};

class Ring : public Circle
{
private:
	int Width;

public:
	Ring(int XN = 0, int YN = 0, int R = 0, int Color = 0, int Wid = 0) : Circle(XN, YN, R, Color), Width(Wid) {}

	void Show() override
	{
		Circle::Show();
		setfillstyle(EMPTY_FILL, getbkcolor());
		pieslice(X, Y, 90, 320, Radius - Width);
	}

	void ChangeSector(int startAngle, int endAngle)
	{
		Circle::ChangeSector(startAngle, endAngle);
		setfillstyle(EMPTY_FILL, getbkcolor());
		pieslice(X, Y, 90, 320, Radius - Width);
	}

	void ChangeColor(int newColor)
	{
		Circle::ChangeColor(newColor);
	}
};