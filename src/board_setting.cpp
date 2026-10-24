#include <iostream>

constexpr int HW = 8;

constexpr int BLACK = 0;

constexpr int WHITE = 1;

constexpr int EMPTY = 2;

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
    m_board[3][3] = WHITE;
    m_board[3][4] = BLACK;
    m_board[4][3] = BLACK;
    m_board[4][4] = WHITE;
  }
  
  void print() const
  {
    std::cout << " ";
    for (int x = 0; x < HW; ++x)
    {
      std::cout << (char)('a' + x) << " ";
    }
    std::cout << '\n';

    for(int y = 0; y < HW; ++y)
    {
      std::cout << 1 + y << " ";

      for(int x = 0; x < HW; ++x)
      {
	int cellState = m_board[y][x];

	std::cout << "XO-"[cellState] << " ";
      }
      std::cout << '\n';
    }

    int nBlack = 0, nWhite = 0;
    for(int y = 0; y < HW; ++y){
      for(int x = 0; x < HW; ++x){
	int cellState = m_board[y][x];

	nBlack += (cellState == BLACK);
	nWhite += (cellState ==WHITE);
      }
    }

    std::cout << "Black" << nBlack << " - " << nWhite << " White\n";

    if(getPlayer() == BLACK){
      std::cout << "Black (X) to move\n";
    }else{
      std::cout << "White (O) to move\n";
    }
  }

  int getPlayer() const
  {
    return m_player;
  }

  int getOpponent() const
  {
    return m_player ^ 1;
  }
  
private:
  int m_board[HW][HW];
  int m_player = BLACK;
};

int main()
{
  Board board;
  board.print();
}
