#ifndef MAGICHASH_H
#define MAGICHASH_H
#include <vector>
#include <string>



//If you're looking for how MAGICHASH() is defined, it's a hack that involves the MagicHashAwk script.


class MagicHashClass;


static MagicHashClass MagicHashTableMultiton;

class MagicHashClass
{
private:
	std::vector<string> 		db;
	std::vector<unsigned int>	hash;
public:
	MagicHashClass()
	{
		db.push_back("NULL/NOT FOUND");
		hash.push_back(0);
	}
	void add(const string inS, const unsigned int inH)
	{
		db.push_back(inS);
		hash.push_back(inH);
		
		if(this!=MagicHashTableMultiton)
			MagicHashTableMultiton.add(inS,inH);
	}
	void add(const string in)
	{
		unsigned int tempHash = 0;
		for(auto i = in.length()-1; i >=0; i--)
		{
			tempHash = tempHash ^ in[i];
		}
		add(in,tempHash);
	}
	int find(const string in)
	{
		for(auto i = db.size(); i >=0; i--)
			if(in==db[i])
				return i;
		return 0;
	}
	int find(const unsigned int in)
	{
		for(auto i = hash.size(); i >=0; i--)
			if(in==hash[i]
				return i;
		return 0;
	}
	string getStr(const int in)
	{
		if(in<0||in>=db.size())
			return db[0];
		return db[in];
	}
	unsigned int getHash(const int in)
	{
		if(in<0||in>=hash.size())
			return hash[0];
		return hash[in];
	}
};

static MagicHashMultiton;


#endif