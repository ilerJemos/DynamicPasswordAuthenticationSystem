package Util;

import java.sql.*;

public class JDBCUtil {


    //system为登陆oracle数据库的用户名     
	private static String url="jdbc:oracle:thin:@127.0.0.1:1521:orcl";  
	//数据库账户
	private static String user = "scott";
	//数据库密码
	private static String password = "Hszmt6117";
	//静态代码块，用于载入driver,只在加载该类的时候执行一次
	static {
		try{
			Class.forName( "oracle.jdbc.driver.OracleDriver" );
		}catch(ClassNotFoundException e){
			e.printStackTrace();
		}
	}
	
	/**
	 * 获取数据库连接，每调用一次该方法就创建一个新连接
	 * @return 如果成功创建连接，则返回连接实体对象，否则返回null
	 */
	public static Connection getConnection(){
		Connection conn = null;
		try{
			conn=DriverManager.getConnection(url, user, password);  
			System.out.println("Connect success!");
		}catch (SQLException e){
			e.printStackTrace();
		}
		return conn;
	}
	
	/**
	 * 关闭数据库连接
	 * @param 数据库连接对象
	 * @return 
	 */
	public static void closeConnection(Connection conn){
		try{
			if((conn != null) && (!conn.isClosed())){
				conn.close();
				conn = null;
			}
		}catch(SQLException e){
			e.printStackTrace();
		}
	}
	
	/**
	 * 关闭数据库查询命令
	 * @param statement语句对象
	 */
	public static void CloseStatement(Statement st){
		try{
			if((st != null) && (!st.isClosed())){
				st.close();
				st = null;
			}
		}catch(SQLException e){
			e.printStackTrace();
		}
	}
	
	/**
	 * 关闭数据库查询命令
	 * @param Preparedstatement语句对象
	 */
	public static void ClosePreparedStatement(PreparedStatement st){
		try{
			if((st != null) && (!st.isClosed())){
				st.close();
				st = null;
			}
		}catch(SQLException e){
			e.printStackTrace();
		}
	}
	
	/**
	 * 关闭数据库查询结果
	 * 
	 * @param ResultSet查询结果对象
	 */
	public static void closeResultSet(ResultSet rs) {
		try {
			if ((rs != null) && (!rs.isClosed())) {
				rs.close();
				rs = null;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//getConnection();
	}

}