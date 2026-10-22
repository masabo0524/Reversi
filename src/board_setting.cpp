constexpr int HW = 8;

constexpr int BLACK = 0;

constexpr int WHITE = 1;

constexpr int EMPTY = 2

class Board{
public:
  Board()
  {
    for( int y = 0; y < HW; ++y)
      {
	for (int x = 0; x < HW; ++x)
	  {
	    m_board[y][x] = EMPTY;
	  }
      }
  }

  m_board[3][3] = WHITE;
  m_board[3][4] = BLACK;
  m_board[4][3] = BLACK;
  m_board[4][4] = WHITE;
private:
  int m_board[HW][HW];
  int m_palyer = BLACK;
}
