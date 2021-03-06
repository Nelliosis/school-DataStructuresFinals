#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

//Structure that holds information about each movie
struct MovieNode
{
  int
        id,
        copies;

  std::string
        title,
        genre,
        prod,
        location;
};

//Structure that holds customer information
struct CustomerNode
{
  int
  		id;

  std::string
        name,
        address;
};

//Structure for customer rental info
struct RentInfo
{
	public:
	  int
	  	cid,
	  	mid;
};

//Declaration of Linked List for MovieList, CustomerList, and vector for RentalInfo
MovieNode node;
CustomerNode cnode;
RentInfo rnode;
list<MovieNode> MovieList;
list<MovieNode>::iterator iter;
list<CustomerNode> CustomerList;
list<CustomerNode>::iterator miter;
vector< pair <int,int> > RentalInfo;
vector< pair <int,int> >::iterator it;

//declaration of Number of Movies per Genre, number of Movies rented by Customer
int posscifi = 5, scifi = 5;
int poshorror = 10, horror = 5;
int posromance = 15, romance = 5;
int posaction = 20, action = 5;
int poscomedy = 25, comedy = 5;
int posnewgenre = 25, newgenre =0;
int rentalnumber = 0;

//Functions
class functions
{
	public:
	  void AddMovie();                   //Austin
	  void RentMovie();                  //Austin
	  void ReturnMovie();                //Austin
	  void displaymovieinfo();           //Junel
	  void display();                    //Junel
	  void avail();                      //Junel
	  bool decision(char);               //Junel
	  void imagehandler(string n);       //Junel
	  void traversedisplay(int i);       //Junel
	  void FromTextToMovieList();        //Junel
    void FromTextToCustomerList();     //Junel
	  bool searchmov(int n);             //Austin
    void AddCustomer();                //Patrick
    void DisplayCustomer();            //Patrick
    void FromTextToRentalInfo();       //Patrick
    void DisplayCustomerRentalInfo();  //Patrick
    void UpdateTextFiles();            //Austin
};

//Function Definitions

//Adds a movie into linked list and writes to MovieList.txt
void functions::AddMovie()
{
	//Variable Declarations
	int ngenre, ncopies;
	string ntitle, nprod, nngenre;
	string id;
	string jpg = ".jpg";

	cout << "<<NEW MOVIE>>\n";
	//Genre chooser since each genre has a corresponding Movie ID
	cout << "GENRE CHOOSER: Please input what is the genre of the movie you are adding.\n\n";
	cout << "Press [1] for Sci-FI\n";
	cout << "Press [2] for Horror\n";
	cout << "Press [3] for Romance\n";
	cout << "Press [4] for Action\n";
	cout << "Press [5] for Comedy\n";
	cout << "Press [6] if you are adding a new genre.\n";
	cout << "Enter Genre: ";

	cin >> ngenre;

	if(ngenre == 1)
	{
		node.genre = "Sci-Fi";
		node.id = 100 + scifi +1;
		scifi++;

		cout << "\n\nVideo ID: " << node.id << endl;
		cin.ignore();

		cout << "Enter Title: ";
		getline(cin, ntitle);

		cout << "Genre: " << node.genre << endl;

		cout << "Enter Production Company: ";
		getline(cin, nprod);
		cout << "Enter Copies: ";
		cin >> ncopies;

		node.title = ntitle;
		node.prod = nprod;
		node.copies = ncopies;

		#if _WIN32
			node.location = "C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Posters\\";
			id = to_string(node.id);
			node.location += id;
			node.location += jpg;
		#else
		 	node.location = "/Users/chikashoki/Documents/GitHub/DSA-FMP/Posters/";
		  	id = to_string(node.id);
		    node.location += id;
		    node.location += jpg;
		#endif

		//Insert New Movie to most Recent Sci-Fi Movie
		iter = MovieList.begin();
		for(int i = 0; i < posscifi; i++)
		{
			iter++;
		}
		MovieList.insert(iter, node);
		posscifi++;
		poshorror++;
		posromance++;
		posaction++;
		poscomedy++;
		posnewgenre++;
	}

	else if(ngenre == 2)
	{
		node.genre = "Horror";
		node.id = 200 + horror +1;
		horror++;

		cout << "\n\nVideo ID: " << node.id << endl;
		cin.ignore();

		cout << "Enter Title: ";
		getline(cin, ntitle);

		cout << "Genre: " << node.genre << endl;

		cout << "Enter Production Company: ";
		getline(cin, nprod);

		cout << "Enter Copies: ";
		cin >> ncopies;

		node.title = ntitle;
		node.prod = nprod;
		node.copies = ncopies;

		#if _WIN32
			node.location = "C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Posters\\";
			id = to_string(node.id);
			node.location += id;
			node.location += jpg;
		#else
		 	node.location = "/Users/chikashoki/Documents/GitHub/DSA-FMP/Posters/";
		  	id = to_string(node.id);
		    node.location += id;
		    node.location += jpg;
		#endif

		//Insert New Movie to most Recent Horror Movie
		iter = MovieList.begin();
		for(int i = 0; i < poshorror; i++)
		{
			iter++;
		}
		MovieList.insert(iter, node);
		poshorror++;
		posromance++;
		posaction++;
		poscomedy++;
		posnewgenre++;
	}

	else if(ngenre == 3)
	{
		node.genre = "Romance";
		node.id = 300 + romance +1;
		romance++;

		cout << "\n\nVideo ID: " << node.id << endl;
		cin.ignore();

		cout << "Enter Title: ";
		getline(cin, ntitle);

		cout << "Genre: " << node.genre << endl;

		cout << "Enter Production Company: ";
		getline(cin, nprod);

		cout << "Enter Copies: ";
		cin >> ncopies;

		node.title = ntitle;
		node.prod = nprod;
		node.copies = ncopies;

		#if _WIN32
			node.location = "C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Posters\\";
			id = to_string(node.id);
			node.location += id;
			node.location += jpg;
		#else
		 	node.location = "/Users/chikashoki/Documents/GitHub/DSA-FMP/Posters/";
		  	id = to_string(node.id);
		    node.location += id;
		    node.location += jpg;
		#endif

		//Insert New Movie to most Recent Romance Movie
		iter = MovieList.begin();
		for(int i = 0; i < posromance; i++)
		{
			iter++;
		}
		MovieList.insert(iter, node);
		posromance++;
		posaction++;
		poscomedy++;
		posnewgenre++;
	}

	else if(ngenre == 4)
	{
		node.genre = "Action";
		node.id = 400 + action +1;
		action++;

		cout << "\n\nVideo ID: " << node.id << endl;
		cin.ignore();

		cout << "Enter Title: ";
		getline(cin, ntitle);

		cout << "Genre: " << node.genre << endl;

		cout << "Enter Production Company: ";
		getline(cin, nprod);

		cout << "Enter Copies: ";
		cin >> ncopies;

		node.title = ntitle;
		node.prod = nprod;
		node.copies = ncopies;

		#if _WIN32
			node.location = "C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Posters\\";
			id = to_string(node.id);
			node.location += id;
			node.location += jpg;
		#else
		 	node.location = "/Users/chikashoki/Documents/GitHub/DSA-FMP/Posters/";
		  	id = to_string(node.id);
		    node.location += id;
		    node.location += jpg;
		#endif

		//Insert New Movie to most Recent Action Movie
		iter = MovieList.begin();
		for(int i = 0; i < posaction; i++)
		{
			iter++;
		}
		MovieList.insert(iter, node);
		posaction++;
		poscomedy++;
		posnewgenre++;
	}

	else if(ngenre == 5)
	{
		node.genre = "Comedy";
		node.id = 500 + comedy +1;
		comedy++;

		cout << "\n\nVideo ID: " << node.id << endl;
		cin.ignore();

		cout << "Enter Title: ";
		getline(cin, ntitle);

		cout << "Genre: " << node.genre << endl;

		cout << "Enter Production Company: ";
		getline(cin, nprod);

		cout << "Enter Copies: ";
		cin >> ncopies;

		node.title = ntitle;
		node.prod = nprod;
		node.copies = ncopies;

		//Insert New Movie to most Recent Comedy Movie
		iter = MovieList.begin();
		for(int i = 0; i < poscomedy; i++)
		{
			iter++;
		}
		MovieList.insert(iter, node);
		poscomedy++;
		posnewgenre++;

		#if _WIN32
			node.location = "C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Posters\\";
			id = to_string(node.id);
			node.location += id;
			node.location += jpg;
		#else
		 	node.location = "/Users/chikashoki/Documents/GitHub/DSA-FMP/Posters/";
		  	id = to_string(node.id);
		    node.location += id;
		    node.location += jpg;
		#endif
	}

	else if(ngenre == 6)
	{
		node.id = 600 + newgenre +1;
		newgenre++;

		cout << "\n\nVideo ID: " << node.id << endl;
		cin.ignore();

		cout << "Enter Title: ";
		getline(cin, ntitle);

		cout << "Enter Genre: ";
		getline(cin, nngenre);
		node.genre = nngenre;

		cout << "Enter Production Company: ";
		getline(cin, nprod);

		cout << "Enter Copies: ";
		cin >> ncopies;

		node.title = ntitle;
		node.prod = nprod;
		node.copies = ncopies;

		#if _WIN32
			node.location = "C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Posters\\";
			id = to_string(node.id);
			node.location += id;
			node.location += jpg;
		#else
		 	node.location = "/Users/chikashoki/Documents/GitHub/DSA-FMP/Posters/";
		  	id = to_string(node.id);
		    node.location += id;
		    node.location += jpg;
		#endif

		//Insert New Movie to most Recent Comedy Movie
		iter = MovieList.begin();
		for(int i = 0; i < posnewgenre; i++)
		{
			iter++;
		}
		MovieList.insert(iter, node);
		posnewgenre++;
	}

	else
	{
		cout << "ERROR. Please enter valid choice.\n";
	}
}

//links copies value between customer and movie (operation: subtraction)
void functions::RentMovie()
{
	int cus, s;
	string name;
	bool found = false;
	bool foundc = false;

	cout << "Enter Customer ID: ";
	cin >> cus;

	for(miter = CustomerList.begin(); miter != CustomerList.end(); miter++)
	{
		if(miter->id == cus)
		{
			name = miter->name;
			foundc = true;
		}

		else
		{
			continue;
		}
	}

	if(foundc == true)
    {

		cout << "<<RENT A MOVIE>>\n";
		cout << "Enter Movie ID: ";
		cin >> s;

		for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
	    {
  		//if the Node ID matches the search ID display movie info
        if (iter->id == s)
        {
        	if(iter->copies > 0)
        	{
    			cout << "Movie to be rented: " << endl;
    			cout << "Video ID" << setw(13) << ": " << iter->id << endl;
  				cout << "Movie Title" << setw(10) << ": " << iter->title << endl;
  				cout << "Genre" << setw(16) << ": " << iter->genre << endl;
  				cout << "Production" << setw(11) << ": " << iter->prod << endl;
  				cout << "Number of Copies" << setw(5) << ": " << iter->copies << endl << endl;

          iter->copies -= 1;

      		cout << "Movie rented to Customer: \n";
      		cout << "Customer ID: " << cus << "\n";
      		cout << "Customer name: " << name << "\n\n";
  			  cout << "Movie Successfully Rented!\n";

  			  RentalInfo.push_back(make_pair(cus, s));
      		found = true;
      		break;
  		    }

  				else
  				{
  					cout<< "Sorry, the movie you are trying to rent has no copies available as of this moment.\n";
  					found = true;
  					break;
  				}
  	    }

  			else
  			{
  				continue;
  			}
	    }
	   }

  	else
  	{
  		cout<< "ERROR. Please enter valid Customer ID.\n";
  	}

}

//links copies between customer and movie (opertion: addition)
void functions::ReturnMovie()
{
	int cus, s;
	string name;
	bool found = false;
	bool foundc = false;
	bool foundcv = false;
	bool foundr = false;

	cout << "Enter Customer ID: ";
	cin >> cus;

	sort(RentalInfo.begin(), RentalInfo.end());

	for(miter = CustomerList.begin(); miter != CustomerList.end(); miter++)
	{
		if(miter->id == cus)
		{
			name = miter->name;
			foundc = true;
			break;
		}
	}

	for(int i = 0; i < RentalInfo.size(); i++)
	{
		if(cus == RentalInfo[i].first)
		{
			foundcv = true;
			break;
		}
	}

	if(foundc == true && foundcv == true)
	{
		cout << "<<RETURN A MOVIE>>\n";
		cout << "Enter Movie ID: ";
		cin >> s;

		for(int i = 0; i < RentalInfo.size(); i++)
		{
			if(cus == RentalInfo[i].first && s == RentalInfo[i].second)
			{
				foundr = true;
				break;
			}
		}

		if(foundr == true)
		{
			for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
		    {
			//if the Node ID matches the search ID display movie info
		    	if (iter->id == s)
		        {
		        	it = RentalInfo.begin();
		 			for(int i = 0; i < RentalInfo.size(); i++)
					{
						if(RentalInfo[i].first == cus && RentalInfo[i].second == s)
						{
							RentalInfo.erase(it);
							break;
						}

						it++;
					}

					iter->copies += 1;
					it = RentalInfo.begin();
					found = true;

					cout<< endl;
					cout<< "Customer Return Info: " << "\n\n";
					cout<< "Customer ID: " << cus << endl;
					cout<< "Customer Name: " << name << endl;
					cout<< "Movie ID: " << s << endl;
					cout<< "Movie Title: " << iter->title << endl;
			    	cout<< "Movie Successfully Returned!\n";

					break;
				   }

	  			 else
	  			 {
	  				continue;
	  			 }
		    }
		}

	    if(found == false)
	    {
	    	cout<< "ERROR. It seems like this customer has not rented a Movie with the corresponding Movie ID.\n";
		}

	}

	else if(foundc == false)
	{
		cout<< "ERROR. Please enter valid Customer ID.\n";
	}

	else if(foundc == true && foundr == false)
	{
		cout<< "ERROR. This particular Customer has not rented any movies.\n";
	}
}

//Displays a single movie's info by searching its ID
void functions::displaymovieinfo()
{
	int s;
	cout << "<<MOVIE INFO>>\n";
	cout << "Enter Movie ID: ";
	cin >> s;

	if(!searchmov(s))
	{
		cout<< "Sorry, the movie you are looking for does not exist in our list.\n";
	}
}

//Displays all of the movies in the Movie List
void functions::display()
{
	//initializes column width
	int colwidth = 40;

	//displays headers of table
	cout<< "<<MOVIE LIST>>\n";
	cout<< left << setw(colwidth) << "Video ID"
	<< left << setw(colwidth) << "Movie Title"
	<< left << setw(colwidth) << "Genre"
	<< left << setw(colwidth) << "Production"
	<< left << setw(colwidth) << "Copies\n";
	traversedisplay(colwidth);
	cout << "\n\n";
}

//Used to check if a movie is available (has enough copies)
void functions::avail()
{
	int s;
	cout << "<<MOVIE INFO>>\n";
	cout << "Enter Movie ID: ";
	cin >> s;
	if(!searchmov(s))
	{
		cout << "Sorry, the movie you are looking for does not exist in our list.\n";
	}

	if(iter->copies > 0)
	{
		cout << "The movie is available!\n";
	}

	else
	{
		cout << "Sorry, we do not have enough copies of this movie as of this moment.\n";
	}
}

//Determines if user wants to try again or not.
bool functions::decision(char d)
{
  if(d == 'y' || d == 'Y')
  return true;
  else
  return false;
}

//Used to open the photo viewer and corresponding Movie Poster
void functions::imagehandler(string n)
{
  //call location based on environment variable
  #if _WIN32
	   string cmd("start C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\ImageGlass_8.0.12.8_x64\\ImageGlass.exe ");
	   cmd += n; //concatenate location and app based on Windows
    #elif __APPLE__
      string terminal("open /System/Applications/Preview.app ");
      terminal += n; //concatenate location and app based on macOS
    #elif __LINUX__
      string terminal("open /System/Applications/Preview.app ");
      terminal += n; //concatenate location and app based on macOS
    #else
        continue;
    #endif

  //To properly utilize rename file directory of image to be displayed
	#if __APPLE__
  	   system(terminal.c_str());
  	#elif _WIN32
  		  system(cmd.c_str());
	  #elif __LINUX__
  	    system("open /System/Applications/Preview.app /Users/chikashoki/Documents/GitHub/Hello-Git/sched.png");
  	#else
  	    continue;
  	#endif
}

//Traverses Linked list while displaying each node
void functions::traversedisplay(int i)
{
    for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
    {
        cout << endl;
        cout << setw(i) << iter->id;
        cout << setw(i) << iter->title;
        cout << setw(i) << iter->genre;
        cout << setw(i) << iter->prod;
        cout << setw(i) << iter->copies;

    }
}

//Converts data from MovieList.txt to a Linked list
void functions::FromTextToMovieList()
{
	//Variable Declarations
	string line1;
	string jpg = ".jpg";
	string id;


	//determines path at runtime
	  #if _WIN32
	  ifstream myfile("C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\MovieList.txt");
	  #else
	  ifstream myfile("/Users/chikashoki/Documents/GitHub/DSA-FMP/MovieList.txt");
	  #endif

	//while file is open, traverse by line
	    if (myfile.is_open())
	    {
	      int count = 0;
	      while ( getline (myfile,line1) )
	      {
	        //count determines which line getfile is at the current node
	        switch(count)
	        {
	          case 0:
	          node.id = stoi(line1);
	            break;
	          case 1:
	            node.title = line1;
	            break;
	          case 2:
	          node.genre = line1;
	            break;
	          case 3:
	          node.prod = line1;
	            break;
	          case 4:
	          node.copies = stoi(line1);
	            break;
	          case 5:
	          	#if _WIN32
      			    node.location = "C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Posters\\";
      			    id = to_string(node.id);
      			    node.location += id;
      			    node.location += jpg;
    			  	#else
      			  	node.location = "/Users/chikashoki/Documents/GitHub/DSA-FMP/Posters/";
      			  	id = to_string(node.id);
      			    node.location += id;
      			    node.location += jpg;
    			  	#endif
	            break;
	          default:
	            break;
	        }

	        //if within the bounds of the node, continue adding
	        if(count < 5)
	        {
	          count++;
	        }
	        //once reached the end of the node, reset count to 0 and push node into list
	        else
	        {
	          count = 0;
	          MovieList.push_back(node);
	        }

	      }
	      myfile.close();

	    }

	    else cout << "Unable to open file" << endl;
	//end of text to MovieList function
}

//Converts data from Customers.txt into a Queue list
void functions::FromTextToCustomerList()
{

	string line;

  	//determines path at runtime
    #if _WIN32
    ifstream myfile("C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Customers.txt");
    #else
    ifstream myfile("/Users/chikashoki/Documents/GitHub/DSA-FMP/Customers.txt");
    #endif

    if(myfile.is_open())
    {
        int count = 0;
        while(getline(myfile,line))
        {
          switch(count)
          {
            case 0:
              cnode.id = stoi(line);
            break;

            case 1:
              cnode.name = line;
            break;

            case 2:
              cnode.address = line;
            break;

            default:
            break;
          }
          if(count < 3)
          {
            count++;
          }
          else
          {
            count = 0;
            CustomerList.push_back(cnode);
          }
        }
        myfile.close();
    }
    else
    {
      cout << "Unable to open file" << endl;
    }

    //end of text to Cutsomer List function
}

//Used to Search for a certain movie using its Movie ID
bool functions::searchmov(int n)
{
	//variable to know if Movie ID is found or not
	bool found = false;
	for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
    {
	//if the Node ID matches the search ID display movie info
        if (iter->id == n)
        {
        	found = true;
        	cout<< "Video ID" << setw(13) << ": " << iter->id << endl;
    			cout<< "Movie Title" << setw(10) << ": " << iter->title << endl;
    			cout<< "Genre" << setw(16) << ": " << iter->genre << endl;
    			cout<< "Production" << setw(11) << ": " << iter->prod << endl;
    			cout<< "Number of Copies" << setw(5) << ": " << iter->copies << endl;
    			imagehandler(iter->location);
        	break;
		}

		else
		{
			continue;
		}

    }

    return found;
}

//Adds a customer into linked list and writes to Customer.txt
void functions::AddCustomer()
{
	int CustomerSize = CustomerList.size();
  	int catcher = 0;
  	cout << "<ADD A CUSTOMER>\n\n";

  	catcher = ++CustomerSize;
  	cnode.id = catcher;
  	cin.ignore();

  	cout << "Customer ID: " << catcher << endl;
  	cout << "Name: ";
  	getline(cin,cnode.name);

  	cout << "Address: ";
  	getline(cin,cnode.address);

  	CustomerList.push_back(cnode);
}

//Displays all of the Customers
void functions::DisplayCustomer()
{
	int cus;
  bool found = true;
	cout << "<<CUSTOMER INFO>>\n";
	cout << "Enter Customer ID to be displayed: ";
	cin >> cus;

	for(miter = CustomerList.begin(); miter != CustomerList.end(); miter++)
	{
		if(miter->id == cus)
		{
			cout << "Customer ID" << setw(10) << ": " << miter->id << endl;
			cout << "Name" << setw(17) << ": " << miter->name << endl;
			cout << "Address" << setw(14) << ": " << miter->address << endl;
      found = true;
      break;
		}

	    else
	    {
	      found = false;
	      continue;
	    }
	}
  if(!found)
  {
    cout << "Sorry, the ID is invalid. Either the customer ID doesn't exist or you have entered the wrong ID.\n\n";
  }
}

//Gets data from rent.txt and converts them into a vector
void functions::FromTextToRentalInfo()
{
	string line;
	int cid;
	int mid;

  	//determines path at runtime
    #if _WIN32
    ifstream myfile("C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Rent.txt");
    #else
    ifstream myfile("/Users/chikashoki/Documents/GitHub/DSA-FMP/Rent.txt");
    #endif

    if(myfile.is_open())
    {
        int count = 0;
        while(getline(myfile,line))
        {
          switch(count)
          {
            case 0:
              cid = stoi(line);
            break;

            case 2:
              mid = stoi(line);
            break;

            default:
            break;
          }
          if(count < 4)
          {
            count++;
          }
          else
          {
            count = 0;
            RentalInfo.push_back(make_pair(cid, mid));
          }
        }
        myfile.close();
    }
    else
    {
      cout << "Unable to open file" << endl;
    }

    //end of text to Rental Info function
}

//Displays the vector
void functions::DisplayCustomerRentalInfo()
{
	int cid;
	int count = 0;
	bool foundc = false;
	cout << "<<VIDEOS RENTED BY A CUSTOMER>>\n";
	cout << "Enter Customer ID: ";
	cin >> cid;

	for(miter = CustomerList.begin(); miter != CustomerList.end(); miter++)
	{
		if(miter->id == cid)
		{
			foundc = true;
			break;
		}

		else
		{
			continue;
		}
	}


  	sort(RentalInfo.begin(), RentalInfo.end());

    if(RentalInfo.empty() && foundc == true)
  	{
  		cout<< "This Customer has not rented any Movie as of this moment.\n";
  	}

  	else if(foundc == false)
  	{
  		cout<< "ERROR. Invalid Customer ID.\n";
	}

  	else
  	{
  		for(int i = 0; i < RentalInfo.size(); i++)
  	    {

  			if(cid == RentalInfo[0].first && count == 0)
  			{
  				cout << "Customer ID: " << RentalInfo[i].first << endl;

  	      for(miter = CustomerList.begin(); miter != CustomerList.end(); miter++)
  				{
  					if(miter->id == RentalInfo[i].first)
  					{
  						cout << "Customer Name: " << miter->name << "\n\n";
  						break;
  					}

  					else
  					{
  						continue;
  					}
  				}

  				cout << "Movies Rented: " << endl;
  				cout << RentalInfo[i].second << " ";

  				for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
  				{
  					if (iter->id == RentalInfo[i].second)
  					{
  						cout << iter->title << endl;
  					        	break;
  					}

  					else
  					{
  						continue;
  					}
  				}
  				count++;
  			}

  			else if(cid == RentalInfo[i].first && RentalInfo[i].first == RentalInfo[i-1].first)
  			{
  				cout << RentalInfo[i].second << " ";

  				for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
  				{
  					if (iter->id == RentalInfo[i].second)
  					{
  						cout << iter->title << endl;
  					        	break;
  					}

  					else
  					{
  						continue;
  					}
  				}
  			}

  			else
  			{
  				cout<< "This Customer has not rented any Movie as of this moment.\n";
  				break;
  			}
  		}
  	}
	cout<< "\n\n";
}

//Updates the three text files
void functions::UpdateTextFiles()
{
	  //writes changes into MovieList.txt
  	#if _WIN32
  	ofstream myfile;
  	myfile.open("C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\MovieList.txt");
  	#else
  	ofstream myfile;
  	myfile.open("/Users/chikashoki/Documents/GitHub/DSA-FMP/MovieList.txt");
  	#endif

  	for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
  	{
    	myfile << iter->id << endl;
    	myfile << iter->title << endl;
    	myfile << iter->genre << endl;
    	myfile << iter->prod << endl;
    	myfile << iter->copies << "\n\n";
  	}
  	myfile.close();

  	//writes changes into Rent.txt
   	#if _WIN32
   	ofstream myfile1;
   	myfile1.open("C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Rent.txt");
   	#else
   	ofstream myfile1;
   	myfile1.open("/Users/chikashoki/Documents/GitHub/DSA-FMP/Rent.txt");
   	#endif

	sort(RentalInfo.begin(), RentalInfo.end());
 	for(int i = 0; i < RentalInfo.size(); i++)
 	{
   		myfile1 << RentalInfo[i].first << endl;

	   	for(miter = CustomerList.begin(); miter != CustomerList.end(); miter++)
	   	{
  			if(miter->id == RentalInfo[i].first)
  	   	{
  			myfile1 << miter->name << endl;
  	   	}

		   	else
		   	{
		    	continue;
		   	}
	   	}

       	myfile1 << RentalInfo[i].second << endl;

       	for(iter = MovieList.begin(); iter != MovieList.end(); iter++)
       	{
        	  if (iter->id == RentalInfo[i].second)
          	{
		    	     myfile1<< iter->title << "\n\n";
        		   break;
			      }

      			else
      			{
      				continue;
      			}
   		   }


	  }
    myfile1.close();

	//Customer.txt
	  #if _WIN32
    ofstream myfile2("C:\\Users\\marbe\\Documents\\github\\DSA-FMP\\Customers.txt");
    #else
    ofstream myfile2("/Users/chikashoki/Documents/GitHub/DSA-FMP/Customers.txt");
    #endif

  	for (miter = CustomerList.begin(); miter != CustomerList.end(); miter++)
  	{
  		myfile2 << miter->id << endl;
  		myfile2 << miter->name << endl;
  		myfile2 << miter->address << "\n\n";
  	}
	myfile2.close();
}
