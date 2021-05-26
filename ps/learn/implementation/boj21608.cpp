#include <iostream>
#include <vector>
#define u_ptr std::unique_ptr
#define vector std::vector

class School {
  int m_n;
  vector<vector<int>> m_room;
  vector<vector<int>> m_favorits;
  vector<int> m_index;

public:
  School() {
    std::cin >> m_n;
    
    m_room.resize(m_n);
    for (vector<int> &vtr_row : m_room)
      vtr_row.resize(m_n, 0);

    int nn = m_n*m_n;
    m_favorits.resize(nn);
    for (int i = 0; i < nn; i++) {
      m_favorits[i].resize(5);
      for (int &student : m_favorits[i])
        std::cin >> student;
    }

    m_index.resize(nn+1);
    for (int i = 0; i < nn; i++)
      m_index[m_favorits[i][0]] = i;
  }

  int countFavoritStudents(int x_student, int x_y, int x_x) {
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    vector<int> &vtr_favorit = m_favorits[m_index[x_student]];
    int n_cnt = 0;

    for (int d = 0; d < 4; d++) {
      int y = x_y + dr[d];
      int x = x_x + dc[d];
      
      if (!(0 <= y && y < m_n && 0 <= x && x < m_n))
        continue;

      for (int i = 1; i < 5; i++) {
        int &stud = vtr_favorit[i];
        if (stud == m_room[y][x]) {
          n_cnt++;
          break;
        }
      }
    }

    return n_cnt;
  }

  int countTotal() {
    int total = 0;
    int arr_value[5] = {0, 1, 10, 100, 1000};
    
    for (int i = 0; i < m_n; i++) {
      for (int j = 0; j < m_n; j++) {
        int n_cnt = countFavoritStudents(m_room[i][j], i, j);
        total += arr_value[n_cnt];
      }
    }

    return total;
  }

  int countBlanks(int x_y, int x_x) {
    int n_cnt = 0;
    
    for (int i = 0; i < 4; i++) {
      int y = (i==3) ? x_y-1 : (i==1) ? x_y+1 : x_y;
      int x = (i==2) ? x_x-1 : (i==0) ? x_x+1 : x_x;
      
      if (0 <= y && y < m_n && 0 <= x && x < m_n && m_room[y][x] == 0) 
        n_cnt++;
    }

    return n_cnt;
  }

  std::pair<int,int> arrangeASeat(int x_student) {
    int n_maxCnt = -1;
    int n_cnt;
    int n_blankCnt;
    int n_maxBlankCnt = -1;
    std::pair<int, int> pair_temp;
    
    auto func_temp = [&n_maxCnt, &pair_temp, &n_maxBlankCnt, this](int x_cnt, int x_i, int x_j)->void{
      n_maxCnt = x_cnt;
      pair_temp = std::make_pair(x_i, x_j);
      n_maxBlankCnt = this->countBlanks(x_i, x_j);
    };

    for (int i = 0; i < m_n; i++) {
      for (int j = 0; j < m_n; j++) {
        if (m_room[i][j] > 0)
          continue;

        if (n_maxCnt < (n_cnt = countFavoritStudents(x_student, i, j)))
          func_temp(n_cnt, i, j);
        else if (n_maxCnt == n_cnt && n_maxBlankCnt < (n_blankCnt = countBlanks(i, j)))
          func_temp(n_cnt, i, j);
      }
    }

    return pair_temp;
  }

  void arrangeAllSeats() {
    for (vector<int> &row : m_favorits) {
      int student = row[0];
      std::pair<int,int> pair_coord = arrangeASeat(student);
      m_room[pair_coord.first][pair_coord.second] = student;
    }
  }

  int solution() {
    arrangeAllSeats();
    return countTotal();
  }
};


int main(void) {
  School *ptrSchool_1 = new School();
  std::cout << ptrSchool_1->solution() << '\n';
  delete ptrSchool_1;
  return 0; 
}