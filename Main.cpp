#pragma once
#include "State.h" 

void pauseAndClear()
{
	system("PAUSE");
	system("CLS");
}

int main()
{
	State s(1, Vector3(0, 0, 0), 1.0);
	s.entities[0] = new Entity(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(0, 0, 0), 1);
	Entity* e = s.entities[0];
	cout << e << endl;
	system("CLS");
	while (true)
	{
		s.updateState();
		cout << e << endl;
		system("CLS");
	}
	return 0;
}