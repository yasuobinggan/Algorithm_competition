/* CCF201612-3 权限查询 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

const int NOVALUE = -1;
const int TRUE = -2;
const int FALSE = -3;

using namespace std;

// 权限
struct _privilege {
    string category;
    int level;
};
vector<_privilege> privilege;

// 角色
struct _role {
    string role;
    int s;
    vector<_privilege> privilege;
};
vector<_role> role;

// 用户
struct _user {
    string user;
    int t;
    vector<string> role;
};
vector<_user> user;

string getcategory(string& s)
{
    int pos = s.find(":");

    if(pos == (int)string::npos)
        return s;
    else
        return s.substr(0, pos);
}

int getlevel(string &s)
{
    int pos = s.find(":");

    if(pos == (int)string::npos)
        return NOVALUE;
    else
        return atoi(s.substr(pos+1, s.length()-1).c_str());
}

int privilegematch(_privilege& p1, _privilege& p2)
{
    if(p1.category != p2.category)
        return FALSE;
    else if(p2.level == NOVALUE) {
        // 不分等级查询
        if(p1.level == NOVALUE)
            return TRUE;
        else
            return p1.level;
    } else {    // p2.level >= 0
        // 分等级查询
        if(p1.level == NOVALUE)
            return TRUE;
        else {
            if(p1.level >= p2.level)
                return TRUE;
            else
                return FALSE;
        }
    }
}

int rolematch(string& rl, _privilege& prvl)
{
    int ans = FALSE;

    for(int i=0; i<(int)role.size(); i++) {
        if(role[i].role == rl) {
            for(int j=0; j<role[i].s; j++) {
                int rt = privilegematch(role[i].privilege[j], prvl);
                if(rt > ans)
                    ans = rt;
            }
        }
    }

    return ans;
}

int query(string& usr, _privilege& prvl)
{
    for(int i=0; i<(int)user.size(); i++) {
        if(user[i].user == usr) {
            int ans = FALSE;
            for(int j=0; j<user[i].t; j++) {
                int rt = rolematch(user[i].role[j], prvl);
                if(rt > ans)
                    ans = rt;
            }
            return ans;
        }
    }

    return FALSE;
}

int main()
{
    int p, r, u, q;

    // 输入权限类别数量
    cin >> p;
    // 输入权限类别
    string c;
    _privilege prvl;
    for(int i=1; i<=p; i++) {
        cin >> c;

        prvl.category = getcategory(c);
        prvl.level = getlevel(c);
        privilege.push_back(prvl);
    }

    // 输入角色数量r
    cin >> r;
    // 输入角色
    for(int i=1; i<=r; i++) {
        _role rl;

        cin >> rl.role >> rl.s;

        for(int j=1; j<=rl.s; j++) {
            cin >> c;

            prvl.category = getcategory(c);
            prvl.level = getlevel(c);
            rl.privilege.push_back(prvl);
        }
        role.push_back(rl);
    }

    // 输入用户数量u
    cin >> u;
    // 输入用户
    for(int i=1; i<=u; i++) {
        _user us;

        cin >> us.user >> us.t;

        for(int j=1; j<=us.t; j++) {
            cin >> c;

            us.role.push_back(c);
        }
        user.push_back(us);
    }

    // 输入查询数量q
    cin >> q;
    string suser;
    for(int i=1; i<=q; i++) {
        // 查询输入
        cin >> suser >> c;

        // 权限分解
        prvl.category = getcategory(c);
        prvl.level = getlevel(c);

        // 查询处理
        int ans = query(suser, prvl);

        // 输出结果
        if(ans == TRUE)
            cout << "true" << endl;
        else if(ans == FALSE)
            cout << "false" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}

/* 这个问题是RBAC问题，即基于角色的权限访问问题，是商业应用中必然出现的问题 */
