//
//  Customer_Curation_Sale_Gallery.cpp
//  ArtGallerySimplified
//
//  implement/define the member functions of the following classes:
//     1. class Customer; 2. class Curation; 3. class Sale; 4. class ArtGallery
//
//created by: Hyok In Kwon
//date:  4/8/2022

#include "Customer_Curation_Sale_Gallery.h"
#include <vector>
#include <algorithm>


namespace NS_ARTGALLERY{
/**
 * @brief Construct a new Customer:: Customer object
 * 
 */
    Customer::Customer(){
        ID = -1;
        name = "na";
        email = "na";
        address = "na";
    }

    Customer::Customer(int theID, string theName, string theEmail, const string theAddr){
        ID = theID;
        name = theName;
        email = theEmail;
        address = theAddr;
    }
//accessors
    int Customer::getID() const{
        return ID;
    }

    string Customer::getName() const{
        return name;
    }

    string Customer::getEmail() const{
        return email;
    }

    string Customer::getAddress() const{
        return address;
    }
//mutators
    void Customer::setID(int theID){
        ID =  theID;
    }

    void Customer::setName(string theName){
        name = theName;
    }

    void Customer::setEmail(string theEmail){
        email = theEmail;
    }

    void Customer::setAddress(string theAddress){
        address = theAddress;
    }

/**
* @brief Construct a new Curation:: Curation object
* 
*/
    Curation::Curation(){
        artworkID = -1;
        artistID = -1;
        curationDate = {1,1,2022};
    }

    Curation::Curation(int theArtworkID, int theArtistID, Date theDate){
        artworkID = theArtworkID;
        artistID = theArtistID;
        curationDate = theDate;
    }
//accessors
    int Curation::getArtworkID() const{
        return artworkID;
    }

    int Curation::getArtistID() const{
        return artistID;
    }

    Date Curation::getCurationDate() const{
        return curationDate;
    }
//mutators
    void Curation::setArtworkID( int theID){
        artworkID = theID;
    }

    void Curation::setArtistID(int theID){
        artistID = theID;
    }

    void Curation::setCurationDate(Date theDate){
        curationDate = theDate;
    }
 /**
 * @brief Construct a new Sale:: Sale object
 * 
 */
    Sale::Sale(){
        customerID  = -1;
        artworkID = -1;
        saleDate = {1,1,2022};
    }

    Sale::Sale(int theCustomerID, int theArtworkID, Date theDate){
        customerID = theCustomerID;
        artworkID = theArtworkID;
        saleDate = theDate;
    }
//accessors
    int Sale::getCustomerID() const{
        return customerID;
    }

    int Sale::getArtworkID() const{
        return artworkID;
    }

    Date Sale::getSaleDate() const{
        return saleDate;
    }
//mutators
    void Sale::setCustomerID(int theID){
        customerID = theID;
    } 

    void Sale::setArtworkID(int theID){
        artworkID = theID;
    }

    void Sale::setSaleDate(Date theDate){
        saleDate = theDate;
    }
    
/**
 * @brief Construct a new Gallery:: Gallery object
 * 
 */
    Gallery::Gallery(){
        ID = -1;
        name = "na";
        address = "na";
        webURL = "na";
    }
//accessors
    int Gallery::getID() const{
        return ID;
    }

    string Gallery::getName() const{
        return name;
    }

    string Gallery::getAddress() const{
        return address;
    }
    
    string Gallery::getWebURL() const{
        return webURL;
    }

    unsigned long Gallery::num_artists() const{
        return artistsList.size();
    } 

    unsigned long Gallery::num_artworksCurated() const{
        return (long) artworksCurated.size();
    }

    unsigned long Gallery::num_artworksForSale() const{
        return (long) artworksForSale.size();
    }

    unsigned long Gallery::num_customers() const{
        return customersList.size();
    }

    unsigned long Gallery::num_curations() const{
        return curationsRecords.size();
    }

    unsigned long Gallery::num_sales() const{
        return salesRecords.size();
    }

    int Gallery::getArtistID(string name, string email) const{
        size_t i;
        for (i =0 ; i < artistsList.size() ; i ++){
            if (artistsList.at(i).getName() == name || artistsList.at(i).getEmail() == email){
                return artistsList.at(i).getID();
            } 
        }
        return -1; //if not found
    }

    int Gallery::getCustomerID(string name, string email) const{
        size_t i;
        for (i =0; i < customersList.size(); i++){
            if (customersList.at(i).getName() == name && customersList.at(i).getEmail() == email){
                return customersList.at(i).getID();
            }
        }
         return -1;
    }

    vector<int> Gallery::getIDsOfArtworksForSale() const {
        vector<int> idV;
        size_t i ;
        for (i =0 ; i < artworksForSale.size(); i++){
            idV.push_back(artworksForSale.at(i).getID());
        }
        return idV;
    }

    vector<int> Gallery::getIDsOfArtistsForSale() const{
        vector<int> idV;
        size_t i ;
        for (i =0; i < artworksForSale.size(); i ++){
            if (std::find(idV.begin(), idV.end(), artworksForSale.at(i).getID()) == idV.end()){
                idV.push_back(artworksForSale.at(i).getID());
            }
        }
        return idV;
    }

    vector<pair<string, int>> Gallery::genArtworksReport(ReportType reportType){
        vector<pair<string, int>> rV; //returned vector
        pair<string, int> p1;
        pair<string, int> p2;
        pair<string, int> p3;
        pair<string, int> p4;
        pair<string, int> p5;
        long int p1Count = 0;
        long int p2Count = 0;
        long int p3Count = 0;
        long int p4Count = 0;
        long int p5Count = 0;
        switch (reportType)
        {
        case ReportType::artType: 
            //painting count
            p1Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                 return toStr_ArtType(a.getType()) == toStr_ArtType(ArtType::painting);
            });
            //photography count
            p2Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtType(a.getType()) == toStr_ArtType(ArtType::photography);  
            });
            //drawing count
            p3Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtType(a.getType()) == toStr_ArtType(ArtType::drawing);  
            });
            //sculpture count
            p4Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtType(a.getType()) == toStr_ArtType(ArtType::sculpture);
            });
            //other count
            p5Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtType(a.getType()) == toStr_ArtType(ArtType::other);
            });
            //making pairs
            p1.first = toStr_ArtType(ArtType::painting);
            p1.second = (int) p1Count;
            p2.first = toStr_ArtType(ArtType::photography);
            p2.second = (int) p2Count;
            p3.first = toStr_ArtType(ArtType::drawing);
            p3.second = (int) p3Count;
            p4.first = toStr_ArtType(ArtType::sculpture);
            p4.second = (int) p4Count;
            p5.first = toStr_ArtType(ArtType::other);
            p5.second = (int) p5Count;
            //pushing all pairs into vector
            rV.push_back(p1);
            rV.push_back(p2);
            rV.push_back(p3);
            rV.push_back(p4);
            rV.push_back(p5);

            break;
        
        case ReportType::artSubject:
            p1Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                 return toStr_ArtSubject(a.getSubject()) == toStr_ArtSubject(ArtSubject::nature);
            });
            p2Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                 return toStr_ArtSubject(a.getSubject()) == toStr_ArtSubject(ArtSubject::portrait);
            });
            p3Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                 return toStr_ArtSubject(a.getSubject()) == toStr_ArtSubject(ArtSubject::animal);
            });
            p4Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                 return toStr_ArtSubject(a.getSubject()) == toStr_ArtSubject(ArtSubject::cartoon);
            });
            p5Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                 return toStr_ArtSubject(a.getSubject()) == toStr_ArtSubject(ArtSubject::other);
            });

            p1.first = toStr_ArtSubject(ArtSubject::nature);
            p1.second = (int) p1Count;
            p2.first = toStr_ArtSubject(ArtSubject::portrait);
            p2.second = (int)p2Count;
            p3.first = toStr_ArtSubject(ArtSubject::animal);
            p3.second = (int) p3Count;
            p4.first = toStr_ArtSubject(ArtSubject::cartoon);
            p4.second = (int) p4Count;
            p5.first = toStr_ArtSubject(ArtSubject::other);
            p5.second = (int) p5Count;
            rV.push_back(p1);
            rV.push_back(p2);
            rV.push_back(p3);
            rV.push_back(p4);
            rV.push_back(p5);

            break;

        case ReportType::artStyle:
            p1Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtStyle(a.getStyle()) == toStr_ArtStyle(ArtStyle::fineArt);
            });
            p2Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtStyle(a.getStyle()) == toStr_ArtStyle(ArtStyle::abstract);
            });
            p3Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtStyle(a.getStyle()) == toStr_ArtStyle(ArtStyle::modern);
            });
            p4Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtStyle(a.getStyle()) == toStr_ArtStyle(ArtStyle::popArt);
            });
            p5Count = count_if(artworksCurated.begin(), artworksCurated.end(), [](Artwork a){
                return toStr_ArtStyle(a.getStyle()) == toStr_ArtStyle(ArtStyle::other);
            });

            p1.first = toStr_ArtStyle(ArtStyle::fineArt);
            p1.second = (int) p1Count;

            p2.first = toStr_ArtStyle(ArtStyle::abstract);
            p2.second = (int) p2Count;

            p3.first = toStr_ArtStyle(ArtStyle::modern);
            p3.second = (int) p3Count;

            p4.first = toStr_ArtStyle(ArtStyle::popArt);
            p4.second = (int) p4Count;

            p5.first = toStr_ArtStyle(ArtStyle::other);
            p5.second = (int) p5Count;
            rV.push_back(p1);
            rV.push_back(p2);
            rV.push_back(p3);
            rV.push_back(p4);
            rV.push_back(p5);

            break;
        }
        return rV;
    }

    void Gallery::setID(int theID){
        ID = theID;
    }

    void Gallery::setName(string theName){
        name = theName;
    }

    void Gallery::setAddress(string theAddr){
        address = theAddr;
    }

    void Gallery::setWebURL(string theURL){
        webURL = theURL;
    }

    int Gallery::addArtist(Artist artist){
        size_t i;
        for (i = 0; i < artistsList.size(); i++){
            if (artistsList.at(i).getName() == artist.getName() || artistsList.at(i).getEmail() == artist.getEmail()){
                return artist.getID();
            }
        }
        artist.setID(uniqueIDs::next_artistID());
        artistsList.push_back(artist);
        return artist.getID();
    }

    int Gallery::addCustomer(Customer customer){
        size_t i;
        for (i = 0; i < customersList.size(); i++){
            if (customersList.at(i).getName() == customer.getName() || customersList.at(i).getEmail() == customer.getEmail()){
                return customer.getID();
            }
        }
        customer.setID(uniqueIDs::next_customerID());
        customersList.push_back(customer);
        return customer.getID();
    }

    void Gallery::curateArtwork(Artwork newItem, Artist artist){
        //setting unique id for newItem
        newItem.setID(uniqueIDs::next_artworkID());
        int artID = Gallery::addArtist(artist);
        artworksCurated.push_back(newItem);
        artworksForSale.push_back(newItem);
        Curation newC(newItem.getID(), artID, getTodaysDate());
        addCuration(newC);
    }

    void Gallery::sellArtwork(int artworkID, Customer customer){
        int custID = Gallery::addCustomer(customer);
        vector<int> forSale = Gallery::getIDsOfArtworksForSale();
        auto it = std::find_if(artworksForSale.begin(), artworksForSale.end(), [artworkID](Artwork a){
            return a.getID() == artworkID;
        });
        if (it != artworksForSale.end()){
            artworksForSale.erase(it);
            Sale newS(custID, artworkID, getTodaysDate());
            addSale(newS);
        }
       
    }

//private helper methods
    void Gallery::addCuration(Curation curation){
        curationsRecords.push_back(curation);
    }

    void Gallery::addSale(Sale sale){
        salesRecords.push_back(sale);
    }








   
 //  implement/define the member functions of the following classes:
//     1. class Customer; 2. class Curation; 3. class Sale; 4. class ArtGallery

}//end of NS_ARTGALLERY