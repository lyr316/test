/*
 * test.h
 *
 *  Created on: May 27, 2014
 *      Author: real
 */

#ifndef TEST_H_
#define TEST_H_

class Car
	{
		int id;
		int start_date;
		int end_date;

	public:
		Car(int id)
	{
			this->id = id;
			start_date = 0;
			end_date = 0;
	}
		void setDate(int start_date, int end_date)
		{
			this->start_date = start_date;
			this->end_date = end_date;
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
	bool InquiryAvailability (int id, int start_date, int end_date)
	{
		if (carFleet[id].start_date > end_date && carFleet[id].end_date < start_date)
			return 1;
		else
			return 0;
	}

	bool placeOrder (int id, int start_date, int end_date)
	{
		if (InquiryAvailability(id, start_date, end_date))
		{
			carFleet[id].setDate(start_date, end_date);
			return 1;
		}

		else
			return 0;
	}

	bool cancelOrder (int id)
	{
		carFleet[id].setDate(0, 0);
		return 1;
	}
};



#endif /* TEST_H_ */
