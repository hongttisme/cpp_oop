#include<iostream>
#include <vector>
#include <limits>
#include <memory>
#include <string>



using namespace std;

const string loginedHomePage = "1: Logout \n2: Create Shipment \n3: List All Created Shipment \n4: Quit Program \n: ";
const string logoutedHomePage = "1: Login \n2: Register New Account \n3: Create A Shipment Without Login \n4: Quit Program \n: ";

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

    string typeArray[8] = {"Cargo", "Container", "Pallets", "Freight",
    "StandardParcel", "FragileItem", "ElectricalAppliances","FruitsandVegetables"};


    Package(){
        packageID = rand();
        type = 4;
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

    int getType(){
        return type;
    }

    virtual double calCost(){
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth()*100+ weight*30;
    }


};

// business package type contain Cargo Container Pallets Freight
class Cargo : public Package{
    public:

    Cargo(){
        Dimension theDimension;
        theDimension.setHeight(10000);
        theDimension.setWidth(1000);
        theDimension.setLength(1000);
        packageID = rand();
        packageDimension = theDimension;
        type = 0;
    }
    double calCost() override{
        return 20000 + 10 * weight;
    }
};

class Container : public Package{
    public:

    Container(){
        Dimension theDimension;
        theDimension.setHeight(20);
        theDimension.setWidth(5);
        theDimension.setLength(5);
        packageID = rand();
        packageDimension = theDimension;
        type = 1;
    }

    double calCost() override{
        return 10000 + 10 * weight;
    }
};

class Pallets : public Package{
    public:

    Pallets(){
        Dimension theDimension;
        theDimension.setHeight(3);
        theDimension.setWidth(3);
        theDimension.setLength(3);
        packageID = rand();
        packageDimension = theDimension;
        type = 2;
    }
    double calCost() override{
        return 2000 + 10 * weight;
    }
};

class Freight : public Package{
    public:

    Freight(){
        Dimension theDimension;
        theDimension.setHeight(10);
        theDimension.setWidth(10);
        theDimension.setLength(5);
        packageID = rand();
        packageDimension = theDimension;
        type = 3;
    }

    double calCost() override{
        return 4000 + 12 * weight;
    }
};

// private package contain StandardParcel FragileItem ElectricalAppliances FruitsandVegetables


class FragileItem : public Package{

    public:

    FragileItem(){
        packageID = rand();
        type = 5;
    }

    double calCost () override{
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth() * 40 + 10 * weight + 100;
    }
};

class ElectricalAppliances : public Package{

    public:

    ElectricalAppliances(){
        packageID = rand();
        type = 6;
    }
    double calCost () override{
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth() * 50 + 10 * weight + 20;
    }
};

class FruitsandVegetables : public Package{

    public:

    FruitsandVegetables(){
        packageID = rand();
        type = 7;
    }
    double calCost () override{
        return packageDimension.getHeight() * packageDimension.getLength() * packageDimension.getWidth() * 30 + 20 * weight + 100;
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

        string shipmentType;

        Package* packagePtr;
        Payment thePayment;
        Origin packageOrigin;
        Destination packageDestination;
        int shipmentID;

        vector<string> methodVector = {"land", "air", "sea"};
        int method;

    public:

        Shipment(){
            shipmentID = rand();
            shipmentType = "Standard Shipment";
        }

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

        virtual double calBasicPaymentAmount(){
            if (method == 0) // land
            {
                return packagePtr->calCost();

            }else if(method == 1){ // air
                return packagePtr->calCost() * 2;

            }else{ // sea
                return packagePtr->calCost() + 10;
            }

        }

        void updatePaymentAmount(){
            thePayment.setPaymentAmount(calBasicPaymentAmount());
        }

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


class BusinessShipment: public Shipment
{
    protected:
    string companyName;

    public:

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

    // business shipment cheaper
    double calBasicPaymentAmount() override{
    if (method == 0) // land
    {
        return packagePtr->calCost() * 0.9;

    }else if(method == 1){ // air
        return packagePtr->calCost() * 2  * 0.9;

    }else{ // sea
        return packagePtr->calCost() + 10  * 0.9;
    }
    }

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


class PrivateShipment: public Shipment
{
    protected:
    public:
    PrivateShipment(){
        shipmentID = rand();
        shipmentType = "Private Shipment";
    }

};



class User{
    protected:

    int userId;
    string username;
    string email;
    string password;
    vector<shared_ptr<Shipment>> shipmentsPtrVec;

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

    void addShipment(unique_ptr<Shipment> newshipmentPtr){
        shipmentsPtrVec.push_back(move(newshipmentPtr));
    }

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
            cout << "No shipment created before!" << endl;
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
        if(inputIsIncorrect) cout << "Incorrect input please input again" << endl << ": " ;
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

    // check if username in use
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


    // get password
    cout << "Input password: ";
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

boolUserpair userLogin(vector<User>& usersVec){
    bool condition;
    User theUser;
    condition = false;
    string userInput;

    boolUserpair result;
    result.loginSuccess = false;

    cout << "Input your username or email: ";
    cin >> userInput;

    for(User user: usersVec){
        if (userInput == user.getEmail() || userInput == user.getUsername()){
            theUser = user;
            condition = true;
        }
    }

    // if username or email in incorrect
    if(!condition){

        cout << "Incorrect username or email! \n1:Enter again\n2:Leave\n: ";
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
        cout << "Incorrect password! \n1:Enter again\n2:Leave\n: ";
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

    cout << "Select your shipment type \n1: Business Shipment \n2: Private Shipment(Maximum 50 kg)\n: ";

    userInput = getUserInputOptionNumber(2);

    if(userInput == "1"){ // business shipment
        cout << "Input your company name: ";
        cin >> userInput;
    }else isBusinessShipment = false; // private shipment

    cout << "Choose whether to ship domestically or internationally \n1: Domestically \n2: Internationally \n: ";
    userInput = getUserInputOptionNumber(2);

    if(userInput == "2"){
        isDomesticallyShipment = false;
    }

    Package* thePackage;
    Dimension theDimension;

    cout << "Choose the category of your package: \n";
    if(isBusinessShipment){
        cout << "1: Cargo \n2: Container \n3: Pallets \n4: Freight \n: ";
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

    }else{
        //
        cout << "1: Standard Parcel \n2: Fragile Item \n3: Electrical Appliances \n4: Fruits and Vegetables \n: ";
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
    if(! isBusinessShipment){
        while (weight > 50)
        {
            cout << "The maximum weight of private shipment is 50 kg! \nInput the weight of your package(kg): ";
            weight = getPositiveDouble();
        }

    }



    if (isDomesticallyShipment)
    {
        shipmentMethod = 0;
    }else{
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

    cout <<"\nPlease do not enter spacing in your address"<< endl;
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

    }else{

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



int main()
{
    bool escProgram = false;
    bool userLogined = false;
    string userInput;
    vector<User> usersVector;
    User currentUser;

    cout << "Welcome to Aseana Parcels" << endl;
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
