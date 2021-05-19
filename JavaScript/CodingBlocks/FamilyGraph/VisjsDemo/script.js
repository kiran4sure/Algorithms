/**
 * Created by kiran kumar.
 */

// https://visjs.org/
class Graph {
    constructor(manager) {
      this.manager = manager;
      this.adjacencyList = new Map();
      this.addVertex(manager);
      this.edges = [];
      this.nodes = [];
    }

    addVertex(vertex) {
        if(!this.adjacencyList.has(vertex))
        {
            this.adjacencyList.set(vertex,[]);
        }
    }

    addEdge(source, destination) {

        if(!this.adjacencyList.has(destination))
            this.addVertex(destination);
        
        this.adjacencyList.get(source).push(destination);
    }

    addMember(member)
    {
        this.addEdge(this.manager, member);
    }

    add_graph1(graph1)
    {
        for(let [k,v] of graph1.adjacencyList.entries())
        {
            console.log(k);
            console.log(v);
            if(this.adjacencyList.has(k))
            {
                
                // let val = graph1.adjacencyList.get(k);
                let val = v.concat(this.adjacencyList.get(k));
                let newval = new Set(val);
                this.adjacencyList.set(k,Array.from(newval));
            }
            else
            {
                this.adjacencyList.set(k,v);
            }
        }
    }

    topologicalSortHelper(node, explored, s) {
        explored.add(node);
        // Marks this node as visited and goes on to the nodes
        // that are dependent on this node, the edge is node ----> n
        for(let val of this.adjacencyList.get(node).values())
        {
            if(!explored.has(val))
            {
                this.topologicalSortHelper(val, explored, s);
            }
        }
        
        // this.edges[node].forEach(n => {
        //    if (!explored.has(n)) {
        //       this.topologicalSortHelper(n, explored, s);
        //    }
        // });
        // All dependencies are resolved for this node, we can now add
        // This to the stack.
        s.push(node);
     }

    topologicalSort() {
        // Create a Stack to keep track of all elements in sorted order
        let s = new Array(this.adjacencyList.length);
        let explored = new Set();
     

        for(let node of this.adjacencyList.keys())
        {
            if(!explored.has(node))
            {
                this.topologicalSortHelper(node, explored, s);
            }
        }

        // For every unvisited node in our graph, call the helper.
        // this.adjacencyList.forEach(node => {
        //    if (!explored.has(node)) {
        //       this.topologicalSortHelper(node, explored, s);
        //    }
        // });
     
        let rev = [];
        while (s.length > 0) {
           rev.push(s.pop());
        }
        console.log("topological sort");
        console.log(rev);
        console.log("======end topological sort=======");
        return rev;
     }

     getSorted()
     {
         let lst = Array.from(this.adjacencyList);

         lst.sort(function(x,y)
         {
            if(x[1].length > y[1].length)
             return -1;
            if(x[1].length < y[1].length)
             return 1;
            return 0;
         });

        console.log("=====sorted=====");
         let fin = [];
         for(let a of lst)
         {
             fin.push(a[0]);
         }
         console.log(fin);
         return fin;
     }

    //  dfs(visited, root)
    //  {
    //     visited.add(root);
    //     console.log(root);

    //     for(val of this.adjacencyList.get(root))
    //     {
    //         if(!visited.has(val))
    //         {
    //             this.dfs(visited, val);
    //         }
    //     }
    //  }

    // formaulate_data(root)
    // {
    //     console.log("=======DFS===============");
    //     let visisted = new Set();
    //     this.dfs(visisted, root);
    //     console.log("===========DFS-END========")
    // }

    generate_data()
    {
        console.log(this.adjacencyList);
        this.nodes = [];
        this.edges = [];
        var cnt = new Map();
        // var visited = new Set();
        let s = this.topologicalSort();
        // this.formaulate_data(s[s.length-1]);
        // console.log("r")
        // let s = this.getSorted();
        while(s.length > 0)
        {
            let n = s.pop();
            
            // this.nodes.push({id:n, label:n});
            console.log("*****" + n);
            console.log(this.adjacencyList.get(n));
            if(Array.isArray(this.adjacencyList.get(n)) && this.adjacencyList.get(n).length > 0)
            {
                if(!cnt.has(n))
                {
                    cnt.set(n,1);
                }
                for(let val of this.adjacencyList.get(n))
                {
                    this.edges.push({from:val, to:n});
                    cnt.set(n, cnt.get(val)+cnt.get(n));   
                }
            }
            else
            {
                cnt.set(n, 1);
            }
        }
        // for(let [key, values] of this.adjacencyList.entries())
        // {
        //     // this.nodes.push({id:key, label:key});
        //     for(let a of values)
        //     {
        //         if(cnt.has(a))
        //         {
        //             cnt.set(a, cnt.get(a)+1);
        //         }
        //         else
        //         {
        //             cnt.set(a,1);
        //         }
        //         if(cnt.has(key))
        //         {
        //             cnt.set(key, cnt.get(a)+cnt.get(key));
        //         }
        //         else
        //         {
        //             cnt.set(key,1);
        //         }
        //         this.edges.push({from:a, to:key});
        //     }
        // }

        console.log(cnt);
        for(let [key, values] of cnt.entries())
        {
            console.log(key + "====>" + values);
            this.nodes.push({id:key, label:key+"["+cnt.get(key)+"]"})
        }
        
    }

    get_data()
    {
        this.generate_data();
        let data = {nodes: this.nodes,
            edges: this.edges};

        return data;
    }
  }


KiranG = new Graph("Kiran");
KiranG.addMember("Prapulla");
KiranG.addMember("Aarya");

KishorG = new Graph("Kishor");
KishorG.addMember("Priya");

SrikantaG = new Graph("Srikanta");
SrikantaG.addMember("Saroja");
SrikantaG.addMember("Kiran");
SrikantaG.addMember("Kishor");

SrikantaG.add_graph1(KiranG);
SrikantaG.add_graph1(KishorG);

ChimmyG = new Graph("Chimmy");
ChimmyG.addMember("Bhagya");
ChimmyG.addMember("Gokul");

PuttaSG = new Graph("PuttaSwamy");
PuttaSG.addMember("Prema");
PuttaSG.addMember("Roja");
PuttaSG.addMember("pinky");

VasuG = new Graph("Vasu");
VasuG.addMember("Shoba");
VasuG.addMember("Udit");
VasuG.addMember("Chintu");

NageshG = new Graph("Nagesh");
NageshG.addMember("NageshWife");
NageshG.addMember("Bharat");
NageshG.addMember("NageshDaughter");

ShivannaG = new Graph("Shivanna");
ShivannaG.addMember("Savitri");
ShivannaG.addMember("Suri");
ShivannaG.addMember("Dhanu");
ShivannaG.addMember("Bhasu");

SuriG = new Graph("Suri");
SuriG.addMember("SuriWife");
SuriG.addMember("SuriElderDaughter");
SuriG.addMember("SuriDaughter");

SiddrajuG = new Graph("Siddaraju");
SiddrajuG.addMember("Yahoda");
SiddrajuG.addMember("Geetha");
SiddrajuG.addMember("Radha");
SiddrajuG.addMember("Deepu");
SiddrajuG.addMember("Veena");

DeepuG = new Graph("Deepu");
DeepuG.addMember("DeepuWife");
DeepuG.addMember("DeepuSon");

GeethaG = new Graph("Geetha");
GeethaG.addMember("Sunil");
GeethaG.addMember("GeethaDaughter");

RadhaG = new Graph("Radha");
RadhaG.addMember("RadhaHubby");
RadhaG.addMember("RadhaFirstSon");
RadhaG.addMember("RadhaSecondSon");

VeenaG = new Graph("Veena");
VeenaG.addMember("Naveen");
VeenaG.addMember("VeenaSon");

RameshG = new Graph("Ramesh");
RameshG.addMember("MahaDevi");
RameshG.addMember("Chethan");
RameshG.addMember("Kavi");

ChethanG = new Graph("Chethan");
ChethanG.addMember("Anusha");
ChethanG.addMember("ChethanSon");

KaviG = new Graph("Kavi");
KaviG.addMember("Ravi");
KaviG.addMember("KaviFirstDaughter");
KaviG.addMember("KaviSecondDaughter");

SureshG = new Graph("Suresh");


AvvaG = new Graph("Avva");
AvvaG.addMember("Suresh");
AvvaG.addMember("Nagesh");
AvvaG.addMember("Ramesh");
AvvaG.addMember("Srikanta");
AvvaG.addMember("Siddaraju");
AvvaG.addMember("PuttaSwamy");
AvvaG.addMember("Shivanna");
AvvaG.addMember("Chimmy");
AvvaG.addMember("Vasu");
AvvaG.add_graph1(KaviG);
AvvaG.add_graph1(SrikantaG);
AvvaG.add_graph1(SureshG);
AvvaG.add_graph1(ChethanG);
AvvaG.add_graph1(RameshG);
AvvaG.add_graph1(SiddrajuG);
AvvaG.add_graph1(GeethaG);
AvvaG.add_graph1(RadhaG);
AvvaG.add_graph1(DeepuG);
AvvaG.add_graph1(VeenaG);
AvvaG.add_graph1(ShivannaG);
AvvaG.add_graph1(SuriG);
AvvaG.add_graph1(KiranG);
AvvaG.add_graph1(KishorG);
AvvaG.add_graph1(NageshG);
AvvaG.add_graph1(VasuG);
AvvaG.add_graph1(PuttaSG);
AvvaG.add_graph1(ChimmyG);




ShashiKumarG = new Graph("ShashiKumar");
ShashiKumarG.addMember("Rajeshwari");
ShashiKumarG.addMember("Lokesh");
ShashiKumarG.addMember("Mahesh");
ShashiKumarG.addMember("Pratibha");

LokeshG = new Graph("Lokesh");
LokeshG.addMember("Swetha");
LokeshG.addMember("Guhan");
LokeshG.addMember("LokeshDaughter");

MaheshG = new Graph("Mahesh");
MaheshG.addMember("Nishitha");
MaheshG.addMember("MaheshDaughter");

PrathibaG = new Graph("Pratibha");
PrathibaG.addMember("Madhu");
PrathibaG.addMember("PrathibaDaughter");

ShashiKumarG.add_graph1(LokeshG);
ShashiKumarG.add_graph1(MaheshG);
ShashiKumarG.add_graph1(PrathibaG);

LoknathG = new Graph("Loknath");
LoknathG.addMember("Gowri");
LoknathG.addMember("Tara");
LoknathG.addMember("Manasa");
LoknathG.addMember("Meghana");
LoknathG.addMember("Sahana");

TaraG = new Graph("Tara");
TaraG.addMember("Nischay");

ManasaG = new Graph("Manasa");
ManasaG.addMember("Ragavendra");

MeghanaG = new Graph("Meghana");
MeghanaG.addMember("Varun");

LoknathG.add_graph1(TaraG);
LoknathG.add_graph1(ManasaG);
LoknathG.add_graph1(MeghanaG);

MohanG = new Graph("Mohan");
MohanG.addMember("Mangala");

YateeshaG = new Graph("Yateesh");
YateeshaG.addMember("Rathna");
YateeshaG.addMember("Vikas");

MahadevG = new Graph("Mahadev");
MahadevG.addMember("Manonmani");
MahadevG.addMember("Keethi");
MahadevG.addMember("Aishwarya");

VijayG = new Graph("Vijay");
VijayG.addMember("Shashi");
VijayG.addMember("Ghanavi");
VijayG.addMember("Rishitha");

ParothamaG = new Graph("Parothama");
ParothamaG.addMember("ShashiKumar");
ParothamaG.addMember("Srikanta");
ParothamaG.addMember("Loknath");
ParothamaG.addMember("Mohan");
ParothamaG.addMember("Mahadev");
ParothamaG.addMember("Vijay");
ParothamaG.addMember("Yateesh");
ParothamaG.add_graph1(ShashiKumarG);
ParothamaG.add_graph1(SrikantaG);
ParothamaG.add_graph1(LoknathG);
ParothamaG.add_graph1(MohanG);
ParothamaG.add_graph1(YateeshaG);
ParothamaG.add_graph1(MahadevG);
ParothamaG.add_graph1(VijayG);

AvvaG.add_graph1(ParothamaG);



onload = function () {

    // create a network
    const container = document.getElementById('container');

    // initialise graph options
    const options = {
        edges: {
            labelHighlightBold: true,
            font: {
                size: 20
            }
        },
        nodes: {
            font: '12px arial red',
            scaling: {
                label: true
            },
            shape: 'icon',
            icon: {
                face: 'FontAwesome',
                code: '\uf1ae',
                size: 40,
                color: '#991133',
            }
        }
    };

    // initialize your network!
    const network = new vis.Network(container);
    network.setOptions(options);


        // let data = AvvaG.get_data();
        let data = ParothamaG.get_data();
        network.setData(data);

};
