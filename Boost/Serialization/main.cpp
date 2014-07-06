#include <fstream>
#include <sstream>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;
/*!
 * gps coordinate
 * illustrates serialization for a simple type
 */
class GpsPosition
{
public:
	GpsPosition(){};
	GpsPosition(int d, int m, float s) : m_degrees(d), m_minutes(m), m_seconds(s) {}
	void Print() const { cout << "deg " << m_degrees << " min " << m_minutes << " sec " << m_seconds << endl; }
private:
    friend class boost::serialization::access;

    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & m_degrees;
        ar & m_minutes;
        ar & m_seconds;
    }
    int m_degrees;
    int m_minutes;
    float m_seconds;
};

int main()
{
    // create and open a character archive for output
    //std::ofstream ofs("filename");
	stringstream ss;

    // create class instance
    const GpsPosition g(35, 59, 24.567f);

    // save data to archive
    {
        boost::archive::text_oarchive oa(ss);
        // write class instance to archive
        oa << g;
        cout << "Inhalt : " << ss.str().c_str() << endl;
    	// archive and stream closed when destructors are called
    }

    // ... some time later restore the class instance to its orginal state
    GpsPosition newg;
    {
        // create and open an archive for input
        //std::ifstream ifs("filename");
        //boost::archive::text_iarchive ia(ifs);
    	boost::archive::text_iarchive ia(ss);
        // read class state from archive
        ia >> newg;

        newg.Print();
        // archive and stream closed when destructors are called
    }
    return 0;
}

