struct List
{
	void push(int data)
	{
		if (listSize)
		{
			Element *current = this->lastElement;
			current->nextEl = new Element(data);

			lastElement = current->nextEl;
		}
		else
		{
			firstElement = new Element(data);
			lastElement = firstElement;
		}
		listSize++;
	}

	void insert(int data, int index)
	{
		int count = 0;
		Element* current = this->firstElement;

		if (index == 1)
		{

			Element* newElement = new Element(data, firstElement);
			firstElement = newElement;
		}
		else
		{
			while (current != nullptr)
			{
				if (count == index - 2)
				{
					Element* temp = current->nextEl;
					Element* newElement = new Element(data, temp);
					current->nextEl = newElement;
				}

				current = current->nextEl;
				count++;
			}
		}
	}

	void delete(int data)
	{
		Element* current = this->firstElement;
		while (current->data == data)
		{
			current = current->nextEl;
			firstElement = current;
		}

		Element* next = current->nextEl;

		while (next != nullptr)
		{
			if (next->data == data)
				current->nextEl = next->nextEl;

			current = current->nextEl;
			next = next->nextEl;
		}
	}

	void swap(int first, int second)
	{
		Element* current1 = this->firstElement;
		Element* next1 = current1->nextEl;

		if (second == current1->data)
		{
			int t = first;
			first = second;
			second = t;
		}

		if (first == current1->data)
		{
			Element* current2 = this->firstElement;
			Element* next2 = current2->nextEl;

			while (next2 != nullptr)
			{
				if (next2->data == second)
					break;

				current2 = current2->nextEl;
				next2 = next2->nextEl;
			}

			current2->nextEl = current1;

			Element temp = Element(current1->data, current1->nextEl);

			current1->nextEl = next2->nextEl;
			next2->nextEl = temp.nextEl;

			firstElement = next2;
		}
		else
		{
			while (next1 != nullptr)
			{
				if (next1->data == first)
					break;

				current1 = current1->nextEl;
				next1 = next1->nextEl;
			}

			Element* current2 = this->firstElement;
			Element* next2 = current2->nextEl;

			while (next2 != nullptr)
			{
				if (next2->data == second)
					break;

				current2 = current2->nextEl;
				next2 = next2->nextEl;
			}

			if (next1->nextEl == next2)
			{
				current1->nextEl = next2;
				next1->nextEl = next2->nextEl;
				next2->nextEl = next1;
			}
			else
			{
				Element temp = Element(next1->data, next1->nextEl);

				current1->nextEl = next2;
				current2->nextEl = next1;

				next1->nextEl = next2->nextEl;
				next2->nextEl = temp.nextEl;
			}
		}
	}

	int get(int index)
	{
		int count = 0;
		Element *current = this->firstElement;

		while (current != nullptr)
		{
			if (count == index)
				return current->data;

			current = current->nextEl;
			count++;
		}

	}

	int* getAllData()
	{
int* data = new int[listSize];
		Element* current = this->firstElement;

int count = 0;
		while (current != nullptr)
		{
			data[count] = current->data;

			current = current->nextEl;
count++;
		}

return data;
	}

private:

	struct Element
	{
		Element* nextEl;

		int data;

		Element(int data, Element *nextEl = nullptr)
		{
			this->data = data;
			this->nextEl = nextEl;
		}
	};

	int listSize = 0;
	Element *firstElement;
	Element *lastElement;
};

int main()
{
}
