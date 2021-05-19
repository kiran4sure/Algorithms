/**
 * Created by aarnavjindal on 19/03/20.
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
            if(this.adjacencyList.has(k))
            {
                let val = graph1.adjacencyList.get(k);
                val = val.concat(this.adjacencyList.get(k));
                val = new Set(val);
                this.adjacencyList[k] = val;
            }
            else
            {
                this.adjacencyList.set(k,graph1.adjacencyList.get(k));
            }
        }
    }

    add_graph(grpah1)
    {
        grpah1.edges.forEach(element => {
           var i;
           var flag = false;
           for(i=0; i<this.edges; i++)
           {
               if(this.edges.to === element.to && this.edges.from === element.from)
               {
                   flag = true;
               }
           }
           if(flag === false)
           {
               this.edges.push(element);
           }
        });
        grpah1.nodes.forEach(element => {
            var i;
            var flag = false;
            for(i=0; i<this.nodes.length; i++)
            {
                if(this.nodes[i].id == element.id)
                {
                    flag = true;
                }
            }
            if(flag == false)
            {
                this.nodes.push(element);
            }
            
        });
    }

    generate_data()
    {
        this.nodes = [];
        this.edges = [];
        var cnt = new Map();
        for(let [key, values] of this.adjacencyList.entries())
        {
            // this.nodes.push({id:key, label:key});
            for(let a of values)
            {
                if(cnt.has(a))
                {
                    cnt.set(a, cnt.get(a)+1);
                }
                else
                    cnt.set(a,1);
                if(cnt.has(key))
                {
                    cnt.set(key, cnt.get(a)+cnt.get(key));
                }
                else
                    cnt.set(key,1);
                // cnt.set(a, cnt[a]+1);
                // cnt.set(key, cnt.get(a)+cnt.get(key));
                this.edges.push({from:a, to:key});
            }
        }

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

g = new Graph("Xiaotian");
g.addMember("Pavan");
g.addMember( "Sathya");
g.addMember( "Trung");
g.addMember( "Rahul Shangavi");
g.addMember( "X1");
g.addMember( "X2");
g.addMember( "X3");
g.addMember( "X4");
g.addMember( "X5");

g2 = new Graph("Manju");
g2.addMember( "Kiran");
g2.addMember( "Deepak");
g2.addMember( "Rahul Soni");
g2.addMember( "Grace");
g2.addMember( "C1");
g2.addMember( "C2");
g2.addMember( "C3");

g3 = new Graph("Andrian");
g3.addMember( "Xiaotian");
g3.addMember( "Manju");
g3.addMember( "Shahid");
g3.addMember( "Zhang Yue");
g3.addMember( "Neil");
g3.addMember( "Lai Yee");
g3.addMember( "Imraan Husain");
g3.addMember( "Earn Kong");
g3.addMember( "Koh Wee");
g3.addMember( "Leong You");

g4 = new Graph("Neil");
g4.addMember( "Amit");
g4.addMember( "Ratikant");
g4.addMember( "Roshan");
g4.addMember( "Eiven");
g4.addMember( "Lew");
g4.addMember( "Nilo Tabago");
g4.addMember( "R1");
g4.addMember( "R2");

g5 = new Graph("Lai Yee");
g5.addMember("Kevin");
g5.addMember("Rahul Baliyan");
g5.addMember("Purushottam");
g5.addMember("Raghavendra Tukka");
g5.addMember("Steven Steven");
g5.addMember("Daniel");
g5.addMember("Ginn Chau");
g5.addMember("Kah Lun Muk");
g5.addMember("Wilson");

g6 = new Graph("Koh Wee");
g6.addMember("Christy Lim");
g6.addMember("Johnson Sen");
g6.addMember("Napolean Gulfo");
g6.addMember("Raoul Nanwani");
g6.addMember("Yee Siang Ho");

g.add_graph1(g2);
g.add_graph1(g6);
g.add_graph1(g4);
g.add_graph1(g5);
g.add_graph1(g3);

onload = function () {

    // create a network
    const container = document.getElementById('container');
    // const genNew = document.getElementById('generate-graph');

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

    function createData(){
        const cities = ['Delhi', 'Mumbai', 'Gujarat', 'Goa', 'Kanpur', 'Jammu', 'Hyderabad', 'Bangalore', 'Gangtok', 'Meghalaya'];

        // Initialising number of nodes in graoh dynamically
        const V = Math.floor(Math.random() * cities.length) + 3;

        // Preparing node data for Vis.js
        let vertices = [];
        for(let i=0;i<V;i++){
            vertices.push({id:i, label: cities[i-1]});
        }
        
        // Preparing edges for Vis.js
        let edges = [];
        for(let i=1;i<V;i++){
            // Picking a neighbour from 0 to i-1 to make edge to
            let neigh = Math.floor(Math.random()*i);

            // Adding the edge between node and neighbour
            let weight = Math.floor(Math.random()*70);
            let clr;
            if(weight >= 0 && weight <= 20)
                clr = 'green';
            else if(weight > 20 && weight <= 35)
                clr = 'blue'
            else if(weight > 35 && weight <=50)
                clr = 'yellow'
            else 
                clr = 'red'

            if(i == 2)
            {
                edges.push({from: i, to: neigh, color: clr,label: String(weight)});
            }
            else
            edges.push({from: i, to: neigh, color: clr,label: String(weight)});
        }

        //Preparing data object for Vis.js
        const data = {
            nodes: vertices,
            edges: edges
        };
        return data;
    }

    // genNew.onclick = function () {
        // Creating and setting data to network
        // let data = createData();
        let data = g.get_data();
        network.setData(data);
    // };

    // genNew.click();
};
