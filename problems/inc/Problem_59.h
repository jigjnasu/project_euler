#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_59_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_59_H_

#include <vector>
#include <string>

namespace project_euler {
    namespace problems {
        class Problem_59 {
        public:
            Problem_59();
            ~Problem_59();

            void sum_of_encrypted_message(const std::string& file) const;

        private:
            std::vector<std::string> m_generate_keys() const;
            std::vector<short> m_get_encrypted_message(const std::string& file) const;
            int m_guess_key(const std::string& key,
                            const std::vector<short>& message) const;
            int m_encrypt_decrypt(const std::string& key,
                                  const std::vector<short>& message) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_59_H_
