package Model;

import javax.servlet.annotation.WebListener;
import javax.servlet.http.HttpSession;
import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionBindingEvent;
import java.util.Objects;

@WebListener
public class Board implements HttpSessionAttributeListener {

    int playerTurn;
    String Board;
    public Board() { }

    @Override
    public String toString() {
        return "BoardState{" +
                "playerTurn=" + playerTurn +
                ", Board='" + Board + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Board that = (Board) o;
        return playerTurn == that.playerTurn &&
                Objects.equals(Board, that.Board);
    }

    @Override
    public int hashCode() {
        return Objects.hash(playerTurn, Board);
    }

    public int getPlayerTurn() {
        return playerTurn;
    }

    public void setPlayerTurn(int playerTurn) {
        this.playerTurn = playerTurn;
    }

    public String getBoard() {
        return Board;
    }

    public void setBoard(String board) {
        Board = board;
    }
}