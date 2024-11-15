#include<iostream>
#include <vector>
#include <limits>
#include <memory>


using namespace std;

const string loginedHomePage = "1: logout \n2: create a shipment \n3: list all created shipment \n4: quit program \n: ";
const string logoutedHomePage = "1: login \n2: register new account \n3: create a shipment without login \n4: quit program \n: ";

class Dimension
{
    protected:
    int width;
    int length;
    int height;

    public:
    Dimension() = default;
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


class Package
{
    protected:
    Dimension packageDimension;
    float weight;
    int type;
    int packageID;

    public:


    Package(){
        packageID = rand();
    }

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

    double calCost(){
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth() * weight;
    }

};



class Payment {
protected:
    string paymentMethod;
    double paymentID;
    double amount;

public:
    Payment(){
        paymentID = rand();
    }

    void setPaymentMethod(string method) {
        if (method == "Online Banking" || method == "Credit Card") {
            paymentMethod = method;
        }
        else {
            cout << "Invalid payment method. Please choose either 'Online Banking' or 'Credit Card'." << endl;
        }
    }

    string getPaymentMethod(){
        return paymentMethod;
    }

    void setPaymentAmount(double i){
        amount = i;
    }

    double getPaymentAmount(){
        return amount;
    }

    double getPaymentID(){
        return paymentID;
    }



};


class Address {
protected:
    string addressLine;
    string zip;
    string city;
    string state;
    string country;

public:
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

    string displayAddress() {
        return addressLine + ", " + zip + " " + city + ", " + state + ", " + country;
    }
};


class Destination : public Address {
protected:
    string estimatedDeliveryDate;

public:
    Destination(){
        estimatedDeliveryDate = "15/11/2024";
    }
    void setEstimatedDeliveryDate(string date) {
        estimatedDeliveryDate = date;
    }

    string getEstimatedDeliveryDate(){
        return estimatedDeliveryDate;
    }
};


class Origin : public Address {
protected:
    string pickupDate;

public:
    Origin(){
        pickupDate = "11/11/2024";
    }
    void setPickupDate(string date) {
        pickupDate = date;
    }

    string getPickupDate(){
        return pickupDate;
    }
};

class Shipment
{
    protected:
        
        string shipmentType = "Standard Shipment";

        Package package;
        Payment thePayment;
        Origin packageOrigin;
        Destination packageDestination;
        int shipmentID;

        vector<string> methodVector = {"land", "air", "sea"};
        int method;

    public:

        Shipment(){
            shipmentID = rand();
        }

        void setPackage(Package pkg)
        {
            package = pkg;
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


        Package getPackage(){
            return package;
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

        virtual double calBasicPaymentAmount(){
            if (method == 0) // land
            {
                return package.calCost();

            }else if(method == 1){ // air
                return package.calCost() * 2;

            }else{ // sea
                return package.calCost() + 10;
            }
            
        }

        void updatePaymentAmount(){
            thePayment.setPaymentAmount(calBasicPaymentAmount());
        }

        virtual void displayShipmentInfo(){
            updatePaymentAmount();

            cout << "\n";
            cout << "-----------------------------------\n";
            cout << "shipment ID: " << shipmentID << endl;
            cout << "shipment type: " << shipmentType << endl;
            cout << "method type: " << methodVector[method] << endl << endl;

            cout << "package ID: "<< package.getPackageID() << endl;
            cout << "package dimmention (L*H*W): " << package.getDimention().getLength() << "x" << package.getDimention().getHeight() << "x" << package.getDimention().getWidth()<< endl;
            cout << "package weight: " << package.getWeight() << endl << endl;
            
            cout << "Origin: " << packageOrigin.displayAddress() << endl;
            cout << "Destination: " << packageDestination.displayAddress() << endl;
            cout << "Pickup date: " << packageOrigin.getPickupDate() << endl;
            cout << "Estimated delivery date: " << packageDestination.getEstimatedDeliveryDate() << endl << endl;

            cout << "Payment method: " << thePayment.getPaymentMethod() << endl;
            cout << "Payment ID: " << thePayment.getPaymentID() << endl;
            cout << "Total price: " << thePayment.getPaymentAmount() << endl;
            cout << "-----------------------------------\n\n";

        }

};


class BusinessShipment: public Shipment
{
    protected:
    string companyName;
    string shipmentType = "Business Shipment";

    public:
    void setCompanyName(string name){
        companyName = name;
    }
    string getCompanyName(){
        return companyName;
    }

    // business shipment cheaper
    double calBasicPaymentAmount() override{
    if (method == 0) // land
    {
        return package.calCost() * 0.9;

    }else if(method == 1){ // air
        return package.calCost() * 2  * 0.9;

    }else{ // sea
        return package.calCost() + 10  * 0.9;
    }
    }

    void displayShipmentInfo() override{
        updatePaymentAmount();

        cout << "\n";
        cout << "-----------------------------------\n";
        cout << "shipment ID: " << shipmentID << endl;
        cout << "shipment type: " << shipmentType << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "method type: " << methodVector[method] << endl << endl;

        cout << "package ID: "<< package.getPackageID() << endl;
        cout << "package dimmention (L*H*W): " << package.getDimention().getLength() << "x" << package.getDimention().getHeight() << "x" << package.getDimention().getWidth()<< endl;
        cout << "package weight: " << package.getWeight() << endl << endl;
        
        cout << "Origin: " << packageOrigin.displayAddress() << endl;
        cout << "Destination: " << packageDestination.displayAddress() << endl;
        cout << "Pickup date: " << packageOrigin.getPickupDate() << endl;
        cout << "Estimated delivery date: " << packageDestination.getEstimatedDeliveryDate() << endl << endl;

        cout << "Payment method: " << thePayment.getPaymentMethod() << endl;
        cout << "Payment ID: " << thePayment.getPaymentID() << endl;
        cout << "Total price: " << thePayment.getPaymentAmount() << endl;
        cout << "-----------------------------------\n\n";

    }
};


class PrivateShipment: public Shipment
{
    protected:
    string shipmentType = "Private Shipment";

};



class User{
    protected:

    int userId;
    string username;
    string email;
    string password;
    vector<unique_ptr<Shipment>> shipmentsPtrVec;
    
    public:
    User() = default;
    User(string nameString, string emailString){
        username = nameString;
        email = emailString;
    }
    void setUserId(int id){
        userId = id;
    }
    void setUserPassword(string pw){
        password = pw;
    }

    // void addShipment(unique_ptr<Shipment> newshipmentPtr){
    //     shipmentsPtrVec.push_back(newshipmentPtr);
    // }

    string getUserPassword(){
        return password;
    }

    string getUsername(){
        return username;
    }

    string getEmail(){
        return email;
    }

    void displayAllShipment(){
        if(shipmentsPtrVec.size() == 0){
            cout << "no shipment created before!" << endl;
            return;
        }
        for(int i = 0; i < shipmentsPtrVec.size(); i++){
            shipmentsPtrVec[i]->displayShipmentInfo();
        }
    }
};

struct boolUserpair{
    bool loginSuccess;
    User theUser;
};

string getUserInputOptionNumber(int numberOfOption){
    string userInput;
    bool inputIsIncorrect = true;

    while(inputIsIncorrect){
        cin >> userInput;
        for(int i = 1; i <= numberOfOption; i++){
            if( userInput == to_string(i))inputIsIncorrect = false;
        }
        if(inputIsIncorrect) cout << "incorrect input please input again" << endl << ": " ;
    }
    return userInput;
}

User registerNewUser(vector<User>& usersVec){
    bool condition;
    string username;
    string email;
    string password;

    // check if email in use
    condition = true;
    while (condition)
    {
        condition = false;
        cout << "input email: ";    
        cin >> email;
        
        for(User theUser: usersVec){
            if (email == theUser.getEmail())
            {
                condition = true;
            }
            
        }
        if (condition){
            cout << "email exist, please input again\n: ";
        }
    }

    // check if username in use
    condition = true;
    while (condition)
    {
        condition = false;
        cout << "input username: ";    
        cin >> username;
        
        for(User theUser: usersVec){
            if (username == theUser.getUsername())
            {
                condition = true;
            }
            
        }
        if (condition){
            cout << "username exist, please input again\n: ";
        }
    }


    // get password
    cout << "input password: ";
    cin >> password;

    User newUser(username, email);
    newUser.setUserPassword(password);

    usersVec.push_back(newUser);
    
    return newUser;
}

double getPositiveDouble() {
    double value;
    cin >> value;

    // Check if the input failed 
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cout << "incorrect input, please input again: ";
        return getPositiveDouble();
    }

    if(value<= 0){
        cout << "the value must be positive please input again: ";
        return getPositiveDouble();
    }

    // Successfully read a double value
    return value;
}

boolUserpair userLogin(vector<User>& usersVec){
    bool condition;
    User theUser;
    condition = false;
    string userInput;

    boolUserpair result;
    result.loginSuccess = false;

    cout << "input your username or email: ";
    cin >> userInput;

    for(User user: usersVec){
        if (userInput == user.getEmail() || userInput == user.getUsername()){
            theUser = user;
            condition = true;
        }
    }

    // if username or email in incorrect
    if(!condition){

        cout << "incorrect username or email! \n1:Enter again\n2:leave\n: ";
        userInput = getUserInputOptionNumber(2);
        if(userInput == "1"){
            return userLogin(usersVec);
        }else{
        return result;
        }
    }

    cout << "input your password: ";
    cin >> userInput;
    if (userInput != theUser.getUserPassword())
    {
        cout << "incorrect password! \n1:Enter again\n2:leave\n: ";
                userInput = getUserInputOptionNumber(2);
        if(userInput == "1"){
            return userLogin(usersVec);
        }else{
        return result;
        }

    }

    result.loginSuccess = true;
    result.theUser = theUser;

    return result;
}

unique_ptr<Shipment> createShipment(){
    string userInput;
    string companyName;
    bool isDomesticallyShipment = true;
    bool isBusinessShipment = true;
    int shipmentMethod;
    double l, h, w, weight;

    cout << "select your shipment type \n1: business shipmment \n2: private shipment\n: ";

    userInput = getUserInputOptionNumber(2);

    if(userInput == "1"){ // business shipment
        cout << "input your company name: ";
        cin >> companyName;
    }else isBusinessShipment = false; // private shipment

    cout << "Choose whether to ship domestically or internationally \n1: domestically \n2: internationally \n: ";
    userInput = getUserInputOptionNumber(2);

    if(userInput == "2"){
        isDomesticallyShipment = false;
    }

    // cout << "Choose the category of your package: ";

    cout << "input the height of your package(mm): ";
    h = getPositiveDouble();
    cout << "input the width of your package(mm): ";
    w = getPositiveDouble();
    cout << "input the lenght of your package(mm): ";
    l = getPositiveDouble();

    cout << "input the weight of your package(kg): ";
    weight = getPositiveDouble();

    Dimension theDimension;
    theDimension.setHeight(h);
    theDimension.setLength(l);
    theDimension.setWidth(w);

    Package thePackage;
    thePackage.setDimension(theDimension);
    thePackage.setWeight(weight);

    if (isDomesticallyShipment)
    {
        shipmentMethod = 0;
    }else{
        cout << "select you shipment method \n1: air \n2: sea \n: ";
        userInput =  getUserInputOptionNumber(2);
        if(userInput == "1"){
            shipmentMethod = 1;
        }else if (userInput == "2"){
            shipmentMethod = 2;
        }

    }

    cout << "\n"; 

    Origin theOrigin;
    Destination theDestination;

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

    cout << "\n";


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

    if (isBusinessShipment)
    {
        auto theShipment = make_unique<BusinessShipment>();
        theShipment->setCompanyName(companyName);

        theShipment->setPackage(thePackage);
        theShipment->setOrigin(theOrigin);
        theShipment->setDestination(theDestination);
        theShipment->setPayment(thePayment);
        theShipment->setMethod(shipmentMethod);

        theShipment->updatePaymentAmount();
        thePayment = theShipment->getPayment();

        cout << "total price: " << thePayment.getPaymentAmount() << " \nselect your payment method \n1: Online Banking \n2: Credit Card \n: ";
        userInput = getUserInputOptionNumber(2);
        if (userInput == "1")
        {
            thePayment.setPaymentMethod("Online Banking");
        }else{
            thePayment.setPaymentMethod("Credit Card");
        }
        theShipment->setPayment(thePayment);

        return theShipment;      

    }else{
        auto theShipment = make_unique<PrivateShipment>();

        theShipment->setPackage(thePackage);
        theShipment->setOrigin(theOrigin);
        theShipment->setDestination(theDestination);
        theShipment->setPayment(thePayment);
        theShipment->setMethod(shipmentMethod);

        theShipment->updatePaymentAmount();
        thePayment = theShipment->getPayment();

        cout << "total price: " << thePayment.getPaymentAmount() << " \nselect your payment method \n1: Online Banking \n2: Credit Card \n: ";
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



int main()
{
    bool escProgram = false;
    bool userLogined = false;
    string userInput;
    vector<User> usersVector;
    User currentUser;

    while(! escProgram){
        if(userLogined){
            cout << loginedHomePage;
            userInput = getUserInputOptionNumber(4);
            if(userInput == "1"){
                cout << "logouted!" << endl;
                userLogined = false;

            }else if(userInput == "2" ){

                // auto newShipmentPtr = createShipment();

                // cout << "created new shippment" << endl;
                // newShipmentPtr->displayShipmentInfo();
                // currentUser.addShipment(move(newShipmentPtr));

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

                    cout << "login successed!\n";
                }else{
                    cout << "login failed!\n";
                }

            }else if(userInput == "2" ){

                userLogined = true;
                currentUser = registerNewUser(usersVector);

                cout << "created new account and logined!" << endl;

            }else if(userInput == "3" ){

                // auto  newShipmentPtr = createShipment();
                // cout << "created new shippment" << endl;
                // newShipmentPtr->displayShipmentInfo();



            }else if(userInput == "4" ){
                escProgram = true;
            }
    
        }
    }
    return 0;
}