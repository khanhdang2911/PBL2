#include "List.h"

template <typename T>
Node<T>::Node(const T &data) : data(data), next(NULL){};

template <typename T>
Node<T>::~Node()
{
    next = NULL;
};

template <typename T>
void Node<T>::Read(ifstream &in)
{
    this->data->Read(in);
}

template <typename T>
string Node<T>::getEmail()
{
    return this->data->getEmail();
}

template <typename T>
string Node<T>::getPassword()
{
    return this->data->getPassword();
}

template <typename T>
string Node<T>::getName()
{
    return this->data->getName();
}
template <typename T>
string Node<T>::getUnit()
{
    return this->data->getUnit();
}

template <typename T>
string Node<T>::getRole()
{
    return this->data->getRole();
}
template <typename T>
void Node<T>::setPrice(int price)
{
    this->data->setPrice(price);
}
template <typename T>
void Node<T>::get()
{
    this->data->Get();
}
template <typename T>
void Node<T>::getDetails()
{
    this->data->GetDetail();
}
template <typename T>
int Node<T>::getId2()
{
    return this->data->getId2();
}
template <typename T>
int Node<T>::getId()
{
    return this->data->getId();
}
template <typename T>
void Node<T>::updateSL(int materials, int product)
{
    int newSL = materials * product;
    this->data->UpdateSL(newSL);
}
template <typename T>
int Node<T>::getSL()
{
    return this->data->getSL();
}

/*------------------------------------LinkedList----------------------------------*/
template <typename T>
LinkedList<T>::LinkedList() : head(NULL), tail(NULL){};

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != NULL)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
};

template <typename T>
void LinkedList<T>::create(const T &data)
{
    Node<T> *newNode = new Node<T>(data);

    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
};

template <typename T>
void LinkedList<T>::remove(int id)
{
    if (head == NULL)
        return;
    bool static check = false;
    Node<T> *del = head;
    Node<T> *prev = NULL;
    while (del)
    {
        if (del->data->getId() == id)
        {
            break;
        }
        else
        {
            prev = del;
            del = del->next;
        }
    }
    if (!del)
    {
        if (!check)
            cout << "The id is not in the list" << endl;
        return;
    }
    else
    {
        if (del == head)
        {
            head = head->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
        else if (del == tail)
        {
            tail = prev;
            prev->next = NULL;
            delete del;
            del = NULL;
        }
        else
        {
            prev->next = del->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
        check = true;
    }
    remove(id);
};

template <typename T>
void LinkedList<T>::remove(int id1, int id2)
{
    if (head == NULL)
        return;
    Node<T> *del = head;
    Node<T> *prev = NULL;
    while (del)
    {
        if (del->data->getId2() == id2 && del->data->getId() == id1)
        {
            break;
        }
        else
        {
            prev = del;
            del = del->next;
        }
    }
    if (!del)
    {
        cout << "The id is not in the list" << endl;
    }
    else
    {
        if (del == head)
        {
            head = head->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
        else if (del == tail)
        {
            tail = prev;
            prev->next = NULL;
            delete del;
            del = NULL;
        }
        else
        {
            prev->next = del->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
    }
};

template <typename T>
void LinkedList<T>::remove(string name)
{
    if (head == NULL)
        return;
    Node<T> *del = head;
    Node<T> *prev = NULL;
    while (del)
    {
        if (del->data->getName() == name)
        {
            break;
        }
        else
        {
            prev = del;
            del = del->next;
        }
    }
    if (!del)
    {
        cout << "\nNot found\n"
             << endl;
    }
    else
    {
        if (del == head)
        {
            head = head->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
        else if (del == tail)
        {
            tail = prev;
            prev->next = NULL;
            delete del;
            del = NULL;
        }
        else
        {
            prev->next = del->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
    }
};

template <typename T>
void LinkedList<T>::sortByName()
{
    if (head == NULL)
        return;
    Node<T> temp = NULL;
    for (Node<T> *temp1 = head; temp1->next != NULL; temp1 = temp1->next)
    {
        for (Node<T> *temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp1->data->getName() > temp2->data->getName())
            {
                temp.data = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp.data;
            }
        }
    }
};

template <typename T>
void LinkedList<T>::sortByDate()
{
    if (head == NULL)
        return;
    Node<T> temp = NULL;
    for (Node<T> *temp1 = head; temp1->next != NULL; temp1 = temp1->next)
    {
        for (Node<T> *temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (compareDate(temp1->data, temp2->data))
            {
                temp.data = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp.data;
            }
        }
    }
};

template <typename T>
LinkedList<T> LinkedList<T>::search(string name)
{
    LinkedList<T> myList;
    for (Node<T> *temp = head; temp != NULL; temp = temp->next)
    {
        string str = temp->data->getName();
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        while (name[name.length() - 1] == ' ')
        {
            name = name.substr(0, name.length() - 1);
        }
        if (str.find(name) != string::npos)
        {
            myList.create(temp->data);
        }
    }
    return myList;
};

template <typename T>
LinkedList<T> LinkedList<T>::search(int id)
{
    LinkedList<T> myList;
    for (Node<T> *temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data->getId() == id)
        {
            myList.create(temp->data);
        }
    }
    return myList;
};

template <typename T>
int LinkedList<T>::getIdByName(string name)
{
    for (Node<T> *temp = head; temp != NULL; temp = temp->next)
    {
        string str = temp->data->getName();
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        while (name[name.length() - 1] == ' ')
        {
            name = name.substr(0, name.length() - 1);
        }
        if (str == name)
        {
            return temp->data->getId();
        }
    }
    return 0;
};

template <typename T>
LinkedList<T> LinkedList<T>::search(int day, int month, int year)
{
    LinkedList<T> myList;
    for (Node<T> *temp = head; temp != NULL; temp = temp->next)
    {
        if (compareEqualDate(temp->data, day, month, year))
        {
            myList.create(temp->data);
        }
    }

    return myList;
};

template <typename T>
int LinkedList<T>::search(int year,int month,bool check)
{
    int revenue = 0;
    for (Node<T> *temp = head; temp != NULL; temp = temp->next)
    {
        if (compareEqualMonth(temp->data, month, year))
        {
            revenue+=temp->data->getPrice();
        }
    }

    return revenue;
};

template <typename T>
LinkedList<T> LinkedList<T>::search(int id1, int id2)
{
    LinkedList<T> myList;

    for (Node<T> *temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data->getId2() == id2 && temp->data->getId() == id1)
        {
            myList.create(temp->data);
        }
    }
    return myList;
};

template <typename T>
void LinkedList<T>::update(int id)
{
    for (Node<T> *temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data->getId() == id)
        {
            temp->data->Update();
        }
    }
};

template <typename T>
void LinkedList<T>::get() const
{
    Node<T> *temp = head;
    while (temp)
    {
        temp->data->Get();
        temp = temp->next;
    }
};
template <typename T>
void LinkedList<T>::getLast() const
{
    tail->data->Get();
};

template <typename T>
void LinkedList<T>::get(int id, bool check) const
{
    Node<T> *temp = head;

    while (temp)
    {
        if (temp->data->getId() == id)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp->data->getRole() == "Administrator" && check)
    {
        temp->data->Get();
    }
    else
    {
        temp->data->GetDetail();
    }
};

template <typename T>
int LinkedList<T>::getSL(int id1, int id2) const
{
    Node<T> *temp = head;
    while (temp)
    {
        if (temp->data->getId2() == id2 && temp->data->getId() == id1)
        {
            return temp->data->getSL();
        }
    }
    return 0;
};

template <typename T>
int LinkedList<T>::getPrice(int id)
{
    Node<T> *temp = head;
    while (temp)
    {
        if (temp->data->getId() == id)
        {
            return temp->data->getPrice();
        }
        temp = temp->next;
    }
    return 0;
};

template <typename T>
int LinkedList<T>::getPrice(string name)
{
    Node<T> *temp = head;
    while (temp)
    {
        if (temp->data->getName() == name)
        {
            return temp->data->getPrice();
        }
        temp = temp->next;
    }
    return 0;
};

template <typename T>
int LinkedList<T>::getIdTail()
{
    if (tail == NULL)
        return 0;
    return tail->data->getId();
};

template <typename T>
void LinkedList<T>::save(ofstream &out)
{
    Node<T> *temp = head;
    out << getSize() << endl;
    while (temp != NULL)
    {
        temp->data->Save(out);
        temp = temp->next;
    }
};

template <typename T>
Node<T> *LinkedList<T>::operator[](int i)
{
    if (head == NULL)
        return NULL;
    Node<T> *temp = head;
    while (i)
    {
        i--;
        temp = temp->next;
    }
    return temp;
};

template <typename T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T> &list)
{
    if (this != &list)
    {
        Node<T> *temp = list.head;
        while (temp)
        {
            this->create(temp->data);
            temp = temp->next;
        }
        temp = NULL;
        delete temp;
    }
    return *this;
}
template <typename T>
void LinkedList<T>::setId()
{
    if (head == NULL)
        return;
    int id = head->data->getId();
    Node<T> *temp = head->next;
    while (temp)
    {
        if (id < temp->data->getId())
        {
            id = temp->data->getId();
        }
        temp = temp->next;
    }
    head->data->SetMa(id);
};

template <typename T>
int LinkedList<T>::getSize()
{
    int size = 0;
    Node<T> *temp = head;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
};
template <typename T>
int LinkedList<T>::getNumberInList(int id)
{
    if (head == NULL)
        return 0;
    int size = 0;
    Node<T> *temp = head;
    while (temp && temp->data->getId() != id)
    {
        size++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return -1;
    }
    return size;
};

template <typename T>
bool LinkedList<T>::ExistEmail(string email)
{
    Node<T> *temp = head;
    while (temp)
    {
        if (temp->data->getEmail() == email)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
};

template <typename T>
bool LinkedList<T>::CheckId(int id)
{
    Node<T> *temp = head;
    while (temp)
    {
        if (temp->data->getId() == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
};

template <typename T>
bool LinkedList<T>::CheckName(string name)
{
    Node<T> *temp = head;
    while (temp)
    {
        string str = temp->data->getName();
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        while (name[name.length() - 1] == ' ')
        {
            name = name.substr(0, name.length() - 1);
        }
        if (str == name)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
};

template <typename T>
bool LinkedList<T>::isEmpty()
{
    if (head == NULL)
        return true;
    return false;
};

template <typename T>
bool LinkedList<T>::ChangePassword(int id)
{
    Node<T> *temp = head;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data->getId() == id)
        {
            temp->data->ChangePassword();
            break;
        }
    }
    return true;
}
/*------------------------------------LinkedList----------------------------------*/

/*-------------------------------------Compare------------------------------------*/
template <typename T>
bool compareDate(const T &obj1, const T &obj2)
{
    if (obj1->getYear() > obj2->getYear())
    {
        return true;
    }
    else if (obj1->getYear() == obj2->getYear())
    {
        if (obj1->getMonth() > obj2->getMonth())
        {
            return true;
        }
        else if (obj1->getMonth() == obj2->getMonth())
        {
            return obj1->getDay() > obj2->getDay();
        }
    }
    return false;
}
template <typename T>
bool compareEqualDate(const T &obj1, int day, int month, int year)
{
    return obj1->getYear() == year && obj1->getMonth() == month && obj1->getDay() == day;
}

template <typename T>
bool compareEqualMonth(const T &obj1,int month, int year)
{
    return obj1->getYear() == year && obj1->getMonth() == month;
}

/*-------------------------------------Compare------------------------------------*/