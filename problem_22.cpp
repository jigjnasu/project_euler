#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

int get_name_score(const std::string& name) {
	int score = 0;
	for (std::size_t i = 0; i < name.size(); ++i)
		score += (name[i] - 'A') + 1;
	return score;
}

void names_scores(const std::string& file) {
	unsigned long long int score = 0;
	std::vector<std::string> names;
	
	std::fstream ifs(file.c_str());
	if (ifs.is_open()) {
		std::string line;
		std::getline(ifs, line);

		std::size_t pos = line.find(",");
		names.push_back(line.substr(1, pos - 2));

		while (pos != std::string::npos) {
			std::size_t next_pos = line.find(",", pos + 1);
			if (next_pos == std::string::npos)
				names.push_back(line.substr(pos + 2, line.size() - pos - 3));
			else
				names.push_back(line.substr(pos + 2, next_pos - pos - 3));
			pos = next_pos;
		}

		std::sort(names.begin(), names.end());

		for (std::size_t i = 0; i < names.size(); ++i)
			score += (i + 1) * get_name_score(names[i]);

		printf("Names Score == [%llu]\n", score);
	} else {
		printf("There is an error while %s opening the file\n", file.c_str());
	}
}

int main() {
	std::clock_t start = clock();
	
	names_scores("data/names.txt");

	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	return 0;
}
