/*
 * test.h
 *
 *  Created on: May 27, 2014
 *      Author: real
 */

#ifndef TEST_H_
#define TEST_H_

class Date
{
public:
	int year;
	int month;
	int day;
	Date (int year = 0, int month = 0, int day = 0)
{
		this->year = year;
		this->month = month;
		this->day = day;
}
};

class Car
	{
		int id;
		Date start;
		Date end;

	public:
		Car(int id = 0)
	{
			this->id = id;
	}
		void setDate(Date start, Date end)
		{
			(this->start).year = start.year;
			(this->start).month = start.month;
			(this->start).day = start.day;

			(this->end).year = end.year;
			(this->end).month = end.month;
			(this->end).day = end.day;
		}

		bool checkAvailability(Date start, Date end)
		{
			if ((this->end).year < start.year && (this->end).month < start.month && (this->end).day < start.day)
				return 1;
			else if ((this->start).year > end.year && (this->start).month > end.month && (this->start).day > end.day)
				return 1;
			else
				return 0;
		}
	};

class RentalCarSystem
{
	Car* carFleet;
public:
	RentalCarSystem(int carNumber)
{
		carFleet = new Car[carNumber];
		for (int i = 0; i < carNumber; i++)
		{
			carFleet[i] = Car(i);
		}
}
	bool inquiryAvailability (int id, Date start, Date end)
	{
		if (carFleet[id].checkAvailability(start, end))
			return 1;
		else
			return 0;
	}

	bool placeOrder (int id, Date start, Date end)
	{
		if (carFleet[id].checkAvailability(start, end))
		{
			carFleet[id].setDate(start, end);
			return 1;
		}

		else
			return 0;
	}

	bool cancelOrder (int id)
	{
		Date d;
		carFleet[id].setDate(d, d);
		return 1;
	}
};



#endif /* TEST_H_ */
