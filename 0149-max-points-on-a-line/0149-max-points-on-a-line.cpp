class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)
            return 1;
        map<vector<double>,int>p,c;
        map<int,int>py,cy;
        int i,j,x1,x2,y1,y2,m=0,n1,n2,d;
        vector<double>a(2,0);
        for(i=0;i<points.size()-1;i++){
            x1=points[i][0],y1=points[i][1];
            for(j=i+1;j<points.size();j++){
                x2=points[j][0],y2=points[j][1];
                if(x1==x2){
                    if(py.find(x1)==py.end())
                        cy[x1]=2,py[x1]=i;
                    else if(py[x1]==i)
                        cy[x1]++;
                    if(cy[x1]>m)
                        m=cy[x1];
                    continue;       
                }
                else{
                    n1=y1-y2,n2=x1*y2-x2*y1,d=x1-x2;
                    a[0]=n1*1.0/d,a[1]=n2*1.0/d;
                    if(p.find(a)==p.end())
                        c[a]=2,p[a]=i;
                    else if(p[a]==i)
                        c[a]++;
                    if(c[a]>m)
                        m=c[a];
                }
            }
        }
        return m;
    }
};