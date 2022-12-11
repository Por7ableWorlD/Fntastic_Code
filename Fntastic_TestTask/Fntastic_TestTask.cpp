#include <iostream>
#include <algorithm>
#include <vector>

std::string ConvertToBracket(const std::string& Line);
void СonvertToLowercase(std::string& Line);
void OutputResultLine(const std::string& OldLine, const std::string& NewLine);

int main()
{
	std::string PlayerInput[]{ "din", "recede", "Success", "(( @" };

	for (const auto& Input : PlayerInput)
	{
		OutputResultLine(Input, ConvertToBracket(Input));
	}

    return 0;
}

std::string ConvertToBracket(const std::string& Line)
{
	std::string CopyLine = Line;
	std::vector<char> ConvertedLine{};

	СonvertToLowercase(CopyLine);

	for (const auto& Symbol : CopyLine)
	{
		if (std::count(Line.begin(), Line.end(), Symbol) > 1)
		{
			ConvertedLine.push_back(')');
		}
		else
		{
			ConvertedLine.push_back('(');
		}
	}

	return std::string(ConvertedLine.begin(), ConvertedLine.end());
}

void СonvertToLowercase(std::string& Line)
{
	for (auto& Symbol : Line)
	{
		if (Symbol >= 'A' && Symbol <= 'Z')
		{
			Symbol += 32;
		}
	}
}

void OutputResultLine(const std::string& OldLine, const std::string& NewLine)
{
	std::cout << OldLine << " => " << NewLine << std::endl;
}

