#include <iostream>
#include <optional>
#include <vector>

constexpr int HW = 8;

constexpr int BLACK = 0;

constexpr int WHITE = 1;

constexpr int EMPTY = 2;

struct Move
{
public:
  int y;
  int x;

  bool flipped[HW][HW] = {};

  Move(int inY, int inX): y(inY), x(inX) {}
};

bool InBounds(int y, int x)
{
  return 0 <= y && y < HW && 0 <= x && x < HW;
}

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

  void move(const Move& move)
  {
    m_board[move.y][move.x] = getPlayer();

    for(int y = 0; y < HW; ++y)
    {
      for(int x = 0; x < HW; ++x)
      {
	if(move.flipped[y][x])
	{
	  m_board[y][x] = getPlayer();
	}
      }
    }
    m_player ^= 1;
  }

  void undo(Move& move)
  {
    m_player ^= 1;

    for(int y = 0; y < HW; ++y)
    {
      for(int x = 0; x < HW; ++x)
      {
	if(move.flipped[y][x])
	{
	  m_board[y][x] = getOpponent();
	}
      }
    }
  }

  std::optional<Move> calcFlipped(int y, int x) const
  {
    if(m_board[y][x] != EMPTY)
    {
      return std::nullopt;
    }

    Move result(y, x);

    constexpr int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    constexpr int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};

    bool flipFound = false;

    for(int i = 0; i < 8; ++i)
    {
      bool opponentDiscFound = false;

      for(int j = 1; j < HW; ++j)
      {
	int y1 = y + dy[i] * j;
	int x1 = x + dx[i] * j;

	if(!InBounds(y1, x1))
	{
	  break;
	}

	if(m_board[y1][x1] == getOpponent())
	{
	  opponentDiscFound = true;
	}
	else if (m_board[y1][x1] == getPlayer())
	{
	  if(opponentDiscFound)
	  {
	    for(int k = 1; k < j; ++k)
	    {
	      int y2 = y + dy[i] * k;
	      int x2 = x + dx[i] * k;

	      result.flipped[y2][x2] = true;
	    }

	    flipFound = true;
	  }
	  break;
	}
	else if(m_board[y1][x1] == EMPTY)
	{
	  break;
	}
      }
    }

    if(flipFound)
    {
      return result;
    }
    else
    {
      return std::nullopt;
    }
  }

  std::vector<Move> getLegalMoves() const
  {
    std::vector<Move> legalMoves;

    for(int y = 0; y < HW; ++y)
    {
      for(int x = 0; x < HW; ++x)
      {
	if(const auto move = calcFlipped(y, x))
	{
	  legalMoves.push_back(*move);
	}
      }
    }
    return legalMoves;
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
