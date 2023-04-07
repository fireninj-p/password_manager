#include "Base64.h"
#include <fstream>


const char fillchar = '=';

static std::string cvt = "ABCDEFGHIJKLMNOPQRSTUVWYXZ"
                         "abcdefghijklmnopqrstuvwyxz"
                         "0123456789+/";
//----< convert vector of bytes to std::string >---------------------
std::string Base64::encode(const std::vector<char>& data)
{
  std::string::size_type  i;
  char               c;
  unsigned int       len = data.size();
  std::string             ret;

  for (i = 0; i < len; ++i)
  {
    c = (data[i] >> 2) & 0x3f;
    ret.append(1, cvt[c]);
    c = (data[i] << 4) & 0x3f;
    if (++i < len)
      c |= (data[i] >> 4) & 0x0f;

    ret.append(1, cvt[c]);
    if (i < len)
    {
      c = (data[i] << 2) & 0x3f;
      if (++i < len)
        c |= (data[i] >> 6) & 0x03;

      ret.append(1, cvt[c]);
    }
    else
    {
      ++i;
      ret.append(1, fillchar);
    }

    if (i < len)
    {
      c = data[i] & 0x3f;
      ret.append(1, cvt[c]);
    }
    else
    {
      ret.append(1, fillchar);
    }
  }

  return(ret);
}
//----< convert std::string to vector of bytes >---------------------

std::vector<char> Base64::decode(const std::string& data)
{
  std::string::size_type  i;
  char c;
  char c1;
  std::string::size_type  len = data.length();
  std::vector<char>  ret;

  for (i = 0; i < len; ++i)
  {
    c = (char) cvt.find(data[i]);
    ++i;
    c1 = (char) cvt.find(data[i]);
    c = (c << 2) | ((c1 >> 4) & 0x3);
    ret.push_back(c);
    if (++i < len)
    {
      c = data[i];
      if (fillchar == c)
        break;
      c = (char) cvt.find(c);
      c1 = ((c1 << 4) & 0xf0) | ((c >> 2) & 0xf);
      ret.push_back(c1);
    }
    if (++i < len)
    {
      c1 = data[i];
      if (fillchar == c1)
        break;
      c1 = (char) cvt.find(c1);
      c = ((c << 6) & 0xc0) | c1;
      ret.push_back(c);
    }
  }
  return(ret);
}

//----< create encoded string from binary file contents >------------

std::string Base64::encodeFromFile(const std::string& inFileName)
{
  std::ifstream in;
  in.open(inFileName.c_str(),std::ios::binary);
  if(!in.good())
  {
    throw std::invalid_argument(std::string("can't open file ") + inFileName);
  }
  std::vector<char> fBytes;
  while(in.good())
    fBytes.push_back(in.get());
  fBytes.pop_back();
  in.close();

  return Base64::encode(fBytes);
}
//----< create new binary file from encoded string >-----------------

void Base64::decodeToFile(
    const std::string& outFileName, const std::string& encodedString
  )
{
  std::ofstream out;
  out.open(outFileName.c_str(),std::ios::binary);
  if(!out.good())
  {
    throw std::invalid_argument(std::string("can't open file ") + outFileName);
  }
  std::vector<char> fdecodedBytes = Base64::decode(encodedString);

  for(unsigned int i=0; i<fdecodedBytes.size(); ++i)
    out.put(fdecodedBytes[i]);
  out.close();
}
