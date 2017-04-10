document.addEventListener('DOMContentLoaded', function(){ 
var cy = cytoscape({
 container: document.querySelector('#cy'),
   boxSelectionEnabled: false,
  autounselectify: true,
 style: cytoscape.stylesheet()
.selector('node')
.css({
 'content': 'data(name)',
'text-valign': 'center',
'color': 'white',
'text-outline-width': 2,
'background-color': '#999',
'text-outline-color': '#999'
})
.selector('edge')
.css({
'label': 'data(label)',
'curve-style': 'bezier',
'target-arrow-shape': 'triangle',
'target-arrow-color': '#E30657',
'line-color': '#0D1B76',
'width': 1
})
.selector(':selected')
.css({
 'background-color': 'black',
'line-color': 'black',
'target-arrow-color': 'black',
'source-arrow-color': 'black'
})
.selector('.faded')
.css({
'opacity': 0.25,
'text-opacity': 0
}),
elements: {
    nodes: [
{ data: { id: '{{q0}}', name: '{{q0}}' } },
{ data: { id: '{qM1}', name: '{qM1}' } },
{ data: { id: '{qmc1}', name: '{qmc1}' } },
{ data: { id: '{qFF}', name: '{qFF}' } },
{ data: { id: '{qss1_qs1}', name: '{qss1_qs1}' } },
{ data: { id: '{q0,qLV1}', name: '{q0,qLV1}' } },
{ data: { id: '{q0}', name: '{q0}_I' } },
{ data: { id: '{qMf}', name: '{qMf}' } },
{ data: { id: '{qmc2}', name: '{qmc2}' } },
{ data: { id: '{qsf}', name: '{qsf}' } },
{ data: { id: '{qss2}', name: '{qss2}' } },
{ data: { id: '{qsf,qsf}', name: '{qsf,qsf}' } },
{ data: { id: '{qLV1}', name: '{qLV1}' } },
{ data: { id: '{q0,qLV1,qLV2}', name: '{q0,qLV1,qLV2}' } },
{ data: { id: '{qmcf}', name: '{qmcf}' } },
{ data: { id: '{qssf}', name: '{qssf}' } },
{ data: { id: '{qLV2}', name: '{qLV2}' } },
{ data: { id: '{qLV1,qLV2}', name: '{qLV1,qLV2}' } },
{ data: { id: '{qLVf}', name: '{qLVf}' } }],
edges: [
{ data: { source: '{q0}', target: '{qM1}' , label: 'letter'} },
{ data: { source: '{q0}', target: '{qmc1}' , label: '>'} },
{ data: { source: '{q0}', target: '{qFF}' , label: 'EOF'} },
{ data: { source: '{q0}', target: '{qss1_qs1}' , label: '+'} },
{ data: { source: '{q0}', target: '{q0,qLV1}' , label: 'n'} },
{ data: { source: '{q0}', target: '{q0}' , label: 't'} },
{ data: { source: '{q0}', target: '{q0}' , label: 'e'} },
{ data: { source: '{qM1}', target: '{qM1}' , label: 'letter'} },
{ data: { source: '{qM1}', target: '{qMf}' , label: 'sep'} },
{ data: { source: '{qM1}', target: '{qMf}' , label: 'EOF'} },
{ data: { source: '{qM1}', target: '{qMf}' , label: 'n'} },
{ data: { source: '{qM1}', target: '{qMf}' , label: 't'} },
{ data: { source: '{qM1}', target: '{qMf}' , label: 'e'} },
{ data: { source: '{qmc1}', target: '{qmc2}' , label: 'Titre'} },
{ data: { source: '{qmc1}', target: '{qmc2}' , label: 'Auteur'} },
{ data: { source: '{qss1_qs1}', target: '{qsf}' , label: 'EOF'} },
{ data: { source: '{qss1_qs1}', target: '{qss2}' , label: '+'} },
{ data: { source: '{qss1_qs1}', target: '{qsf,qsf}' , label: 'n'} },
{ data: { source: '{qss1_qs1}', target: '{qsf,qsf}' , label: 't'} },
{ data: { source: '{qss1_qs1}', target: '{qsf,qsf}' , label: 'e'} },
{ data: { source: '{q0,qLV1}', target: '{qM1}' , label: 'letter'} },
{ data: { source: '{q0,qLV1}', target: '{qLV1}' , label: 'sep'} },
{ data: { source: '{q0,qLV1}', target: '{qmc1}' , label: '>'} },
{ data: { source: '{q0,qLV1}', target: '{qFF}' , label: 'EOF'} },
{ data: { source: '{q0,qLV1}', target: '{qss1_qs1}' , label: '+'} },
{ data: { source: '{q0,qLV1}', target: '{q0,qLV1,qLV2}' , label: 'n'} },
{ data: { source: '{q0,qLV1}', target: '{q0}' , label: 't'} },
{ data: { source: '{q0,qLV1}', target: '{q0}' , label: 'e'} },
{ data: { source: '{q0}', target: '{qM1}' , label: 'letter'} },
{ data: { source: '{q0}', target: '{qmc1}' , label: '>'} },
{ data: { source: '{q0}', target: '{qFF}' , label: 'EOF'} },
{ data: { source: '{q0}', target: '{qss1_qs1}' , label: '+'} },
{ data: { source: '{q0}', target: '{q0,qLV1}' , label: 'n'} },
{ data: { source: '{q0}', target: '{q0}' , label: 't'} },
{ data: { source: '{q0}', target: '{q0}' , label: 'e'} },
{ data: { source: '{qmc2}', target: '{qmcf}' , label: 'sep'} },
{ data: { source: '{qmc2}', target: '{qmcf}' , label: 'EOF'} },
{ data: { source: '{qss2}', target: '{qssf}' , label: 'sep'} },
{ data: { source: '{qss2}', target: '{qssf}' , label: 'EOF'} },
{ data: { source: '{qLV1}', target: '{qLV1}' , label: 'sep'} },
{ data: { source: '{qLV1}', target: '{qLV2}' , label: 'n'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{qM1}' , label: 'letter'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{qLV1,qLV2}' , label: 'sep'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{qmc1}' , label: '>'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{qFF}' , label: 'EOF'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{qss1_qs1}' , label: '+'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{q0,qLV1,qLV2}' , label: 'n'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{q0}' , label: 't'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{q0}' , label: 'e'} },
{ data: { source: '{q0,qLV1,qLV2}', target: '{qLVf}' , label: 'V-{sepEtEOF}'} },
{ data: { source: '{qLV2}', target: '{qLV2}' , label: 'sep'} },
{ data: { source: '{qLV2}', target: '{qLVf}' , label: 'V-{sepEtEOF}'} },
{ data: { source: '{qLV1,qLV2}', target: '{qLV1,qLV2}' , label: 'sep'} },
{ data: { source: '{qLV1,qLV2}', target: '{qLV2}' , label: 'n'} },
{ data: { source: '{qLV1,qLV2}', target: '{qLVf}' , label: 'V-{sepEtEOF}'} },
]
},
layout: {
 name: 'grid',
padding: 10
}
});
cy.on('tap', 'node', function(e){
var node = e.cyTarget;
var neighborhood = node.neighborhood().add(node);
cy.elements().addClass('faded');
neighborhood.removeClass('faded');
});
 cy.on('tap', function(e){
if( e.cyTarget === cy ){
cy.elements().removeClass('faded');
}
 });
 });
