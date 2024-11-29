#include<iostream>
#include <vector>
#include <limits>
#include <memory>
#include <string>



using namespace std;

// Constants for the logged-in and logged-out homepage options
const string loginedHomePage = "1: Logout \n2: Create Shipment \n3: List All Created Shipment \n4: Quit Program \n: ";
const string logoutedHomePage = "1: Login \n2: Register New Account \n3: Create A Shipment Without Login \n4: Quit Program \n: ";


// Class to handle the dimensions of packages
class Dimension
{
    protected:
    int width;
    int length;
    int height;

    public:
    Dimension() = default;
    // Setters for dimensions
    void setLength(int l)
    {
        length = l;
    }

    void setWidth(int w)
    {
        width = w;
    }

    void setHeight(int h)
    {
        height = h;
    }

    // Getters for dimensions
    int getLength()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

};

// Base class for all types of packages
class Package
{
    protected:
    Dimension packageDimension;
    float weight;

    int type;
    int packageID;

    public:
    // Array representing different package types
    string typeArray[8] = {"Cargo", "Container", "Pallets", "Freight",
    "StandardParcel", "FragileItem", "ElectricalAppliances","FruitsandVegetables"};


    Package(){
        packageID = rand();  // Generate a random package ID
        type = 4;    // Default type is StandardParcel
    }

    // Setters
    void setDimension(Dimension d){
        packageDimension = d;
    }

    void setWeight(float w)
    {
        weight = w;
    }

    void setType(int t)
    {
        type = t;
    }

    void setPackageID(int i){
        packageID = i;
    }


    // Getters
    Dimension getDimention(){
        return packageDimension;
    }

    float getWeight()
    {
        return weight;
    }

    int getPackageID()
    {
        return packageID;
    }

    int getType(){
        return type;
    }

    // Method to calculate the cost of the package
    virtual double calCost(){
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth()*100+ weight*30;
    }


};

// Derived classes for business package types
// Class for Cargo package
class Cargo : public Package{
    public:

    Cargo(){
        Dimension theDimension;
        theDimension.setHeight(10000);
        theDimension.setWidth(1000);
        theDimension.setLength(1000);
        packageID = rand();
        packageDimension = theDimension;
        type = 0;   // Type set to Cargo
    }

    // Override cost calculation for Cargo
    double calCost() override{
        return 20000 + 10 * weight;
    }
};

// Class for Container package
class Container : public Package{
    public:

    Container(){
        Dimension theDimension;
        theDimension.setHeight(20);
        theDimension.setWidth(5);
        theDimension.setLength(5);
        packageID = rand();
        packageDimension = theDimension;
        type = 1;   // Type set to Container
    }

    // Override cost calculation for Container
    double calCost() override{
        return 10000 + 10 * weight;
    }
};


// Class for Pallets package
class Pallets : public Package{
    public:

    Pallets(){
        Dimension theDimension;
        theDimension.setHeight(3);
        theDimension.setWidth(3);
        theDimension.setLength(3);
        packageID = rand();
        packageDimension = theDimension;
        type = 2;   // Type set to Pallets
    }

    // Override cost calculation for Pallets
    double calCost() override{
        return 2000 + 10 * weight;
    }
};

// Class for Freight package
class Freight : public Package{
    public:

    Freight(){
        Dimension theDimension;
        theDimension.setHeight(10);
        theDimension.setWidth(10);
        theDimension.setLength(5);
        packageID = rand();
        packageDimension = theDimension;
        type = 3;   // Type set to Freight
    }

    // Override cost calculation for Freight
    double calCost() override{
        return 4000 + 12 * weight;
    }
};

// Derived classes for private package types

// Class for FragileItem package
class FragileItem : public Package{

    public:

    FragileItem(){
        packageID = rand();
        type = 5;   // Type set to FragileItem
    }
    // Override cost calculation for FragileItem
    double calCost () override{
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth() * 40 + 10 * weight + 100;
    }
};

// Class for ElectricalAppliances package
class ElectricalAppliances : public Package{

    public:

    ElectricalAppliances(){
        packageID = rand();
        type = 6;   // Type set to ElectricalAppliances
    }

    // Override cost calculation for ElectricalAppliances
    double calCost () override{
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth() * 50 + 10 * weight + 20;
    }
};

// Class for Fruits and Vegetables packag
class FruitsandVegetables : public Package{

    public:

    FruitsandVegetables(){
        packageID = rand();
        type = 7;   // Type set to Fruits and Vegetables
    }
    // Override cost calculation for Fruits and Vegetables
    double calCost () override{
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth() * 30 + 20 * weight + 100;
    }
};

// Class to handle payment information
class Payment {
protected:
    string paymentMethod;   // Payment method (e.g., Online Banking, Credit Card)
    int paymentID;    // Unique payment ID
    double amount;  // Payment amount

public:
    Payment(){
        paymentID = rand(); // Generate a random payment ID
    }
    // Setter
    // Set the payment method with validation
    void setPaymentMethod(string method) {
        if (method == "Online Banking" || method == "Credit Card") {
            paymentMethod = method;
        }
        else {
            cout << "Invalid payment method. Please choose either 'Online Banking' or 'Credit Card'." << endl;
        }
    }

    void setPaymentAmount(int i){
        amount = i;
    }

    // Getters for payment details

    string getPaymentMethod(){
        return paymentMethod;
    }

    double getPaymentAmount(){
        return amount;
    }

    int getPaymentID(){
        return paymentID;
    }

};

// Base class for addresses
class Address {
protected:
    string addressLine;
    string zip;
    string city;
    string state;
    string country;

public:
    // Setters for address components
    void setAddress(string addr) {
        addressLine = addr;
    }

    void setZip(string z) {
        zip = z;
    }

    void setCity(string c) {
        city = c;
    }

    void setState(string s) {
        state = s;
    }

    void setCountry(string n) {
        country = n;
    }

    // Getters for address components
    string getAddress() {
        return addressLine;
    }

    string getZip() {
        return zip;
    }

    string getCity() {
        return city;
    }

    string getState() {
        return state;
    }

    string getCountry(){
        return country;
    }

    // Display the full address
    string displayAddress() {
        return addressLine + ", " + zip + " " + city + ", " + state + ", " + country;
    }
};

// Destination address class inheriting from Address
class Destination : public Address {
protected:
    string estimatedDeliveryDate;

public:
    Destination(){
        estimatedDeliveryDate = "18/12/2024";   // Default delivery date
    }
    void setEstimatedDeliveryDate(string date) {
        estimatedDeliveryDate = date;
    }

    string getEstimatedDeliveryDate(){
        return estimatedDeliveryDate;
    }
};

// Origin address class inheriting from Address
class Origin : public Address {
protected:
    string pickupDate;

public:
    Origin(){
        pickupDate = "11/12/2024";  // Default pickup date
    }
    void setPickupDate(string date) {
        pickupDate = date;
    }

    string getPickupDate(){
        return pickupDate;
    }
};

// Class to represent a shipment
class Shipment
{
    protected:

        string shipmentType;    // Type of shipment (e.g., Business or Private)
        Package* packagePtr;    // Pointer to the associated package
        Payment thePayment;     // Payment information
        Origin packageOrigin;   // Origin address
        Destination packageDestination; // Destination address
        int shipmentID;         // Unique shipment ID

        vector<string> methodVector = {"land", "air", "sea"};
        int method;     // Selected shipping method

    public:

        Shipment(){
            shipmentID = rand();    // Generate a random shipment ID
            shipmentType = "Standard Shipment"; // Default shipment type
        }

        // Setters for shipment details
        void setPackage(Package* pkg)
        {
            packagePtr = pkg;
        }

        void setPayment(Payment pay){
            thePayment = pay;
        }

        void setMethod(int m){
            method = m;
        }

        void setOrigin(Origin o){
            packageOrigin = o;
        }


        void setDestination(Destination d){
            packageDestination = d;
        }

        // Getters for shipment details
        Package* getPackage(){
            return packagePtr;
        }

        Payment getPayment(){
            return thePayment;
        }

        int getMethod(){
            return method;
        }

        Origin getOrigin(){
            return packageOrigin;
        }


        Destination getDestination(){
            return packageDestination;
        }

        int get_shipmentID()
        {
            return shipmentID;
        }

        // Calculate the basic payment amount based on the method
        virtual double calBasicPaymentAmount(){
            if (method == 0) // land shipping
            {
                return packagePtr->calCost();

            }else if(method == 1){ // air shipping
                return packagePtr->calCost() * 2;

            }else{ // sea shipping
                return packagePtr->calCost() + 10;
            }

        }

        // Update the payment amount
        void updatePaymentAmount(){
            thePayment.setPaymentAmount(calBasicPaymentAmount());
        }

        // Display detailed shipment information
        virtual void displayShipmentInfo(){
            updatePaymentAmount();

            cout << endl;
            cout << "-----------------------------------" << endl;
            cout << "Shipment ID: " << shipmentID << endl;
            cout << "Shipment Type: " << shipmentType << endl;
            cout << "Method Type: " << methodVector[method] << endl << endl;

            cout << "Package ID: "<< packagePtr->getPackageID() << endl;
            cout << "Package Dimension (L*H*W): " << packagePtr->getDimention().getLength() << "x" << packagePtr->getDimention().getHeight() << "x" << packagePtr->getDimention().getWidth()<< endl;
            cout << "Package Weight: " << packagePtr->getWeight() << endl;
            cout << "Package Type: " << packagePtr->typeArray[packagePtr->getType()] << endl << endl;

            cout << "Origin: " << packageOrigin.displayAddress() << endl;
            cout << "Destination: " << packageDestination.displayAddress() << endl;
            cout << "Pickup Date: " << packageOrigin.getPickupDate() << endl;
            cout << "Estimated Delivery Date: " << packageDestination.getEstimatedDeliveryDate() << endl << endl;

            cout << "Payment Method: " << thePayment.getPaymentMethod() << endl;
            cout << "Payment ID: " << thePayment.getPaymentID() << endl;
            cout << "Total Price: " << thePayment.getPaymentAmount() << endl;
            cout << "-----------------------------------"<< endl<< endl;

        }

};

// Derived class for Business shipments
class BusinessShipment: public Shipment
{
    protected:
    string companyName; // Name of the business

    public:

    // Derived class with different constructor
    BusinessShipment(){
        shipmentID = rand();
        shipmentType = "Business Shipment";
    }

    void setCompanyName(string name){
        companyName = name;
    }
    string getCompanyName(){
        return companyName;
    }

    // override the calBasicPaymentAmount method
    // Business shipments have discounted costs
    double calBasicPaymentAmount() override{
    if (method == 0) // land shipping
    {
        return packagePtr->calCost() * 0.9;

    }else if(method == 1){ // air shipping
        return packagePtr->calCost() * 2  * 0.9;

    }else{ // sea shipping
        return packagePtr->calCost() + 10  * 0.9;
    }
    }

    // Display detailed information for Business shipments
    void displayShipmentInfo() override{
        updatePaymentAmount();

        cout << endl;
        cout << "-----------------------------------" << endl;
        cout << "Shipment ID: " << shipmentID << endl;
        cout << "Shipment Type: " << shipmentType << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Method Type: " << methodVector[method] << endl << endl;

        cout << "Package ID: "<< packagePtr->getPackageID() << endl;
        cout << "Package Dimension (L*H*W): " << packagePtr->getDimention().getLength() << "x" << packagePtr->getDimention().getHeight() << "x" << packagePtr->getDimention().getWidth()<< endl;
        cout << "Package Weight: " << packagePtr->getWeight() << endl << endl;
        cout << "Package Type: " << packagePtr->typeArray[packagePtr->getType()] << endl << endl;


        cout << "Origin: " << packageOrigin.displayAddress() << endl;
        cout << "Destination: " << packageDestination.displayAddress() << endl;
        cout << "Pickup Date: " << packageOrigin.getPickupDate() << endl;
        cout << "Estimated Delivery Date: " << packageDestination.getEstimatedDeliveryDate() << endl << endl;

        cout << "Payment Method: " << thePayment.getPaymentMethod() << endl;
        cout << "Payment ID: " << thePayment.getPaymentID() << endl;
        cout << "Total Price: " << thePayment.getPaymentAmount() << endl;
        cout << "-----------------------------------"<< endl<< endl;

    }
};

// Derived class for Private shipments
class PrivateShipment: public Shipment
{
    protected:
    public:
    PrivateShipment(){
        shipmentID = rand();
        shipmentType = "Private Shipment";
    }

};


// Class to represent a user in the system
class User{
    protected:

    int userId;
    string username;
    string email;
    string password;
    vector<shared_ptr<Shipment>> shipmentsPtrVec;   // Vector to store all shipments created by the user

    public:
    User() = default;   // Default constructor
    User(string nameString, string emailString){
        username = nameString;
        email = emailString;
    }

    // Setters for user details
    void setUserId(int id){
        userId = id;
    }
    void setUserPassword(string pw){
        password = pw;
    }

    // Add a shipment to the user's list of shipments
    void addShipment(unique_ptr<Shipment> newshipmentPtr){
        shipmentsPtrVec.push_back(move(newshipmentPtr));
    }

    // Getters for user details
    string getUserPassword(){
        return password;
    }

    string getUsername(){
        return username;
    }

    string getEmail(){
        return email;
    }

    // Display all shipments created by the user
    void displayAllShipment(){
        if(shipmentsPtrVec.size() == 0){
            cout << "No shipment created before!" << endl;
            return;
        }
        for(int i = 0; i < shipmentsPtrVec.size(); i++){
            shipmentsPtrVec[i]->displayShipmentInfo();
        }
    }
};

// Struct to return login results, indicating success and the corresponding user
struct boolUserpair{
    bool loginSuccess;  // Indicates if login was successful
    User theUser;
};

// Helper function to get valid user input for options
string getUserInputOptionNumber(int numberOfOption){
    string userInput;
    bool inputIsIncorrect = true;

    while(inputIsIncorrect){
        cin >> userInput;
        for(int i = 1; i <= numberOfOption; i++){
            if( userInput == to_string(i))inputIsIncorrect = false;
        }
        if(inputIsIncorrect) cout << "Incorrect input please input again" << endl << ": " ;
    }
    return userInput;
}

// Function to register a new user
User registerNewUser(vector<User>& usersVec){
    bool condition;
    string username;
    string email;
    string password;

    // Validate if email is already in use
    condition = true;
    while (condition)
    {
        condition = false;
        cout << "Input email: ";
        cin >> email;

        for(User theUser: usersVec){
            if (email == theUser.getEmail())
            {
                condition = true;
            }

        }
        if (condition){
            cout << "Email exist, please input again\n: ";
        }
    }

    // Validate if username is already in use
    condition = true;
    while (condition)
    {
        condition = false;
        cout << "Input username: ";
        cin >> username;


        for(User theUser: usersVec){
            if (username == theUser.getUsername())
            {
                condition = true;
            }

        }
        if (condition){
            cout << "Username exist, please input again\n: ";
        }
    }


    // Input password
    cout << "Input password: ";
    cin >> password;

    User newUser(username, email);
    newUser.setUserPassword(password);

    usersVec.push_back(newUser);

    return newUser;
}

// Helper function to get a positive double input
double getPositiveDouble() {
    double value;
    cin >> value;

    // Handle invalid input
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input, please input again: ";
        return getPositiveDouble();
    }

    if(value<= 0){
        cout << "The value must be positive please input again: ";
        return getPositiveDouble();
    }

    // Successfully read a double value
    return value;
}

// Function to handle user login
boolUserpair userLogin(vector<User>& usersVec){
    bool condition;
    User theUser;
    condition = false;
    string userInput;

    boolUserpair result;
    result.loginSuccess = false;

    // Prompt for username or email
    cout << "Input your username or email: ";
    cin >> userInput;

    for(User user: usersVec){
        if (userInput == user.getEmail() || userInput == user.getUsername()){
            theUser = user;
            condition = true;
        }
    }

    // If username or email is incorrect
    if(!condition){

        cout << "Incorrect username or email! \n1:Enter again\n2:Leave\n: ";
        userInput = getUserInputOptionNumber(2);
        if(userInput == "1"){
            return userLogin(usersVec);
        }else{
        return result;
        }
    }

    // Prompt for password
    cout << "input your password: ";
    cin >> userInput;
    // If password is incorrect
    if (userInput != theUser.getUserPassword())
    {
        // handle case when password is incorrect
        cout << "Incorrect password! \n1:Enter again\n2:Leave\n: ";
                userInput = getUserInputOptionNumber(2);
        if(userInput == "1"){
            return userLogin(usersVec);
        }else{
        return result;
        }

    }

    // Login successful, store result in struct
    result.loginSuccess = true;
    result.theUser = theUser;

    return result;
}

// Function to create a shipment
unique_ptr<Shipment> createShipment(){
    string userInput;
    string companyName;
    bool isDomesticallyShipment = true;
    bool isBusinessShipment = true;
    int shipmentMethod;
    double l, h, w, weight;

    // Prompt
    cout << "Select your shipment type \n1: Business Shipment \n2: Private Shipment(Maximum 50 kg)\n: ";

    userInput = getUserInputOptionNumber(2);

    if(userInput == "1"){ // business shipment
        cout << "Input your company name (Without Spacing): ";
        cin >> userInput;
    }else isBusinessShipment = false; // private shipment

    cout << "Choose whether to ship domestically or internationally \n1: Domestically \n2: Internationally \n: ";
    userInput = getUserInputOptionNumber(2);

    // user input internationally shipment
    if(userInput == "2"){
        isDomesticallyShipment = false;
    }

    Package* thePackage;
    Dimension theDimension;

    // Prompt
    cout << "Choose the category of your package: \n";
    // if is business shipment
    if(isBusinessShipment){
        cout << "1: Cargo \n2: Container \n3: Pallets \n4: Freight \n: ";

        // handle user input
        userInput = getUserInputOptionNumber(4);
        if(userInput == "1"){
            thePackage = new Cargo;
        }else if (userInput == "2"){
            thePackage = new Container;

        }else if (userInput == "3"){
            thePackage = new Pallets;

        }else if (userInput == "4"){
            thePackage = new Freight;

        }

    }else{ // if is private shipment

        // Prompt
        cout << "1: Standard Parcel \n2: Fragile Item \n3: Electrical Appliances \n4: Fruits and Vegetables \n: ";

        // handle user input
        userInput = getUserInputOptionNumber(4);
        if(userInput == "1"){
            thePackage = new Package;
        }else if (userInput == "2"){
            thePackage = new FragileItem;

        }else if (userInput == "3"){
            thePackage = new ElectricalAppliances;

        }else if (userInput == "4"){
            thePackage = new FruitsandVegetables;

        }

    // Get package information
    cout << "Input the height of your package(m): ";
    h = getPositiveDouble();

    cout << "Input the width of your package(m): ";
    w = getPositiveDouble();
    cout << "Input the length of your package(m): ";
    l = getPositiveDouble();

    theDimension.setHeight(h);
    theDimension.setLength(l);
    theDimension.setWidth(w);

    }

    cout << "Input the weight of your package(kg): ";
    weight = getPositiveDouble();

    // handle the incorrect weight of private shipment ( < 50kg )
    if(! isBusinessShipment){
        while (weight > 50)
        {
            cout << "The maximum weight of private shipment is 50 kg! \nInput the weight of your package(kg): ";
            weight = getPositiveDouble();
        }

    }


    // if is domestically shipment
    if (isDomesticallyShipment)
    {
        shipmentMethod = 0;
    }else{ // if is internationally shipment
        // get and handle shipment method information
        cout << "Select you shipment method \n1: Air \n2: Sea \n: ";
        userInput =  getUserInputOptionNumber(2);
        if(userInput == "1"){
            shipmentMethod = 1;
        }else if (userInput == "2"){
            shipmentMethod = 2;
        }

    }

    cout << endl;

    Origin theOrigin;
    Destination theDestination;

    // get shipment address
    if(isDomesticallyShipment){
        theOrigin.setCountry("Malaysia");
    }else{
        cout << "Input your pick up country: ";
        cin >> userInput;

        theOrigin.setCountry(userInput);

    }

    cout << "Input your pick up state: ";
    cin >> userInput;

    theOrigin.setState(userInput);


    cout << "Input your pick up city: ";
    cin >> userInput;
    theOrigin.setCity(userInput);

    cout << "Input your pick up zip code: ";
    cin >> userInput;
    theOrigin.setZip(userInput);

    cout << "Input your pick up address line: ";
    cin >> userInput;
    theOrigin.setAddress(userInput);

    cout << endl;


    if(isDomesticallyShipment){
        theDestination.setCountry("Malaysia");
    }else{
        cout << "Input your destination country: ";
        cin >> userInput;
        theDestination.setCountry(userInput);

    }

    cout << "Input your destination state: ";
    cin >> userInput;
    theDestination.setState(userInput);


    cout << "Input your destination city: ";
    cin >> userInput;
    theDestination.setCity(userInput);

    cout << "Input your destination zip code: ";
    cin >> userInput;
    theDestination.setZip(userInput);

    cout << "Input your destination address line: ";
    cin >> userInput;
    theDestination.setAddress(userInput);

    cout << "\n";


    Payment thePayment;

    // create business Shipment object
    if (isBusinessShipment)
    {

        thePackage->setWeight(weight);

        auto theShipment = make_unique<BusinessShipment>();
        theShipment->setCompanyName(companyName);

        theShipment->setPackage(thePackage);
        theShipment->setOrigin(theOrigin);
        theShipment->setDestination(theDestination);
        theShipment->setPayment(thePayment);
        theShipment->setMethod(shipmentMethod);

        theShipment->updatePaymentAmount();
        thePayment = theShipment->getPayment();

        cout << "Total price: " << thePayment.getPaymentAmount() << " \nSelect your payment method \n1: Online Banking \n2: Credit Card \n: ";
        userInput = getUserInputOptionNumber(2);
        if (userInput == "1")
        {
            thePayment.setPaymentMethod("Online Banking");
        }else{
            thePayment.setPaymentMethod("Credit Card");
        }
        theShipment->setPayment(thePayment);

        return theShipment;


    }else{  // create create Shipment object

        thePackage->setDimension(theDimension);
        thePackage->setWeight(weight);
        auto theShipment = make_unique<PrivateShipment>();

        theShipment->setPackage(thePackage);
        theShipment->setOrigin(theOrigin);
        theShipment->setDestination(theDestination);
        theShipment->setPayment(thePayment);
        theShipment->setMethod(shipmentMethod);

        theShipment->updatePaymentAmount();
        thePayment = theShipment->getPayment();

        cout << "Total price: " << thePayment.getPaymentAmount() << " \nSelect your payment method \n1: Online Banking \n2: Credit Card \n: ";
        userInput = getUserInputOptionNumber(2);
        if (userInput == "1")
        {
            thePayment.setPaymentMethod("Online Banking");
        }else{
            thePayment.setPaymentMethod("Credit Card");
        }
        theShipment->setPayment(thePayment);

        return theShipment;
    }


}


// Main program loop
int main()
{
    bool escProgram = false;
    bool userLogined = false;
    string userInput;
    vector<User> usersVector;
    User currentUser;

    cout << endl << "Welcome to Aseana Parcels" << endl << endl;
    cout << "WARNING!!: This program has error handling, the only thing is there must be NO SPACES.\nPlease pay special attention to the address part. " << endl << endl;
    while(! escProgram){
        if(userLogined){
            cout << loginedHomePage;
            userInput = getUserInputOptionNumber(4);
            if(userInput == "1"){
                cout << "Logout Successful!" << endl;
                userLogined = false;

            }else if(userInput == "2" ){

                auto newShipmentPtr = createShipment();

                cout << "Created New Shipment" << endl;
                newShipmentPtr->displayShipmentInfo();
                currentUser.addShipment(move(newShipmentPtr));

            }else if(userInput == "3" ){
                currentUser.displayAllShipment();

            }else if(userInput == "4" ){
                escProgram = true;
            }


        }else{

            cout << logoutedHomePage;
            userInput = getUserInputOptionNumber(4);
            if(userInput == "1"){
                boolUserpair loginResult = userLogin(usersVector);
                if(loginResult.loginSuccess){

                    userLogined = true;
                    currentUser = loginResult.theUser;

                    cout << "Login Successfully!"<< endl <<"";
                }else{
                    cout << "Login Failed!"<< endl <<"";
                }

            }else if(userInput == "2" ){

                userLogined = true;
                currentUser = registerNewUser(usersVector);

                cout << "Created new account and login!" << endl;

            }else if(userInput == "3" ){

                auto newShipmentPtr = createShipment();

                cout << "Created new shipment" << endl;
                newShipmentPtr->displayShipmentInfo();


            }else if(userInput == "4" ){
                escProgram = true;
            }

        }
    }
    return 0;
}
