<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="0liver">
<packages>
<package name="AZ8">
<description>&lt;b&gt;MINIATURE PC BOARD RELAY&lt;/b&gt;&lt;p&gt;
Source: www.azettler.com .. AZ8-1ch-12DSE.PDF</description>
<wire x1="-10.59" y1="7.75" x2="-10.59" y2="-8.225" width="0.2032" layer="21"/>
<wire x1="10.5068" y1="7.75" x2="-10.59" y2="7.75" width="0.2032" layer="21"/>
<wire x1="10.5068" y1="7.75" x2="10.5068" y2="-8.225" width="0.2032" layer="21"/>
<wire x1="10.5068" y1="-8.2268" x2="-10.59" y2="-8.2268" width="0.2032" layer="21"/>
<pad name="1" x="8.89" y="6.35" drill="1.4" diameter="2.5" rot="R180"/>
<pad name="2" x="-3.81" y="6.35" drill="1.4" diameter="2.5" rot="R180"/>
<pad name="5" x="-8.89" y="6.35" drill="1.4" diameter="2.5" rot="R180"/>
<pad name="3" x="-8.89" y="-1.27" drill="1.4" diameter="2.5" rot="R180"/>
<pad name="4" x="-3.81" y="-6.35" drill="1.4" diameter="2.5" rot="R180"/>
<text x="-10.16" y="-10.16" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.81" y="-1.27" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="TSR-1-RELAIS">
<wire x1="0" y1="-13.2" x2="0" y2="0" width="0.127" layer="21"/>
<circle x="2.35" y="-1.4" radius="0.9" width="0.127" layer="21"/>
<circle x="2.35" y="-4.4" radius="0.9013875" width="0.127" layer="21"/>
<circle x="10.35" y="-1.4" radius="0.9" width="0.127" layer="21"/>
<circle x="9.35" y="-5" radius="0.55" width="0.127" layer="21"/>
<circle x="1.85" y="-11.6" radius="0.55" width="0.127" layer="21"/>
<wire x1="0" y1="-13.2" x2="10.3" y2="-13.2" width="0.127" layer="21"/>
<wire x1="10.3" y1="-13.2" x2="12.3" y2="-13.2" width="0.127" layer="21"/>
<wire x1="12.3" y1="-13.2" x2="12.3" y2="-11.2" width="0.127" layer="21"/>
<wire x1="12.3" y1="-11.2" x2="12.3" y2="0" width="0.127" layer="21"/>
<wire x1="12.3" y1="0" x2="7.15" y2="0" width="0.127" layer="21"/>
<pad name="O" x="2.35" y="-1.4" drill="1.8" diameter="2.54" rot="R180"/>
<pad name="P" x="10.35" y="-1.4" drill="1.8" diameter="2.54" rot="R180"/>
<pad name="C" x="2.35" y="-4.4" drill="1.8" diameter="2.54"/>
<pad name="S1" x="9.35" y="-5" drill="1.1" shape="square"/>
<pad name="S2" x="1.85" y="-11.6" drill="1.1" shape="square"/>
<wire x1="7.15" y1="0" x2="5.15" y2="0" width="0.127" layer="21"/>
<wire x1="5.15" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<wire x1="10.3" y1="-13.2" x2="12.3" y2="-11.2" width="0.127" layer="21"/>
<circle x="11.8" y="-12.7" radius="0.353553125" width="0.127" layer="21"/>
<wire x1="7.15" y1="0" x2="5.15" y2="0" width="0.127" layer="21" curve="-180"/>
<wire x1="10.4" y1="-2.35" x2="10.4" y2="-3.05" width="0.017" layer="23"/>
<wire x1="10.4" y1="-3.05" x2="6.97" y2="-3.05" width="0.017" layer="23"/>
<wire x1="6.97" y1="-3.05" x2="4.02" y2="-3.95" width="0.017" layer="23"/>
<wire x1="3.3" y1="-1.45" x2="4.15" y2="-1.45" width="0.017" layer="23"/>
<wire x1="4.15" y1="-1.45" x2="4.15" y2="-2.15" width="0.017" layer="23"/>
<wire x1="4.15" y1="-3.3" x2="4.15" y2="-4.25" width="0.017" layer="23"/>
<wire x1="4.15" y1="-4.25" x2="3.3" y2="-4.25" width="0.017" layer="23"/>
<wire x1="2.55" y1="-11.6" x2="5.05" y2="-11.6" width="0.017" layer="23"/>
<wire x1="5.05" y1="-11.6" x2="5.05" y2="-11.05" width="0.017" layer="23"/>
<wire x1="5.05" y1="-11.05" x2="6.65" y2="-11.05" width="0.017" layer="23"/>
<wire x1="6.65" y1="-11.05" x2="6.65" y2="-11.6" width="0.017" layer="23"/>
<wire x1="6.65" y1="-11.6" x2="6.65" y2="-12.2" width="0.017" layer="23"/>
<wire x1="6.65" y1="-12.2" x2="5.05" y2="-12.2" width="0.017" layer="23"/>
<wire x1="5.05" y1="-12.2" x2="5.05" y2="-11.6" width="0.017" layer="23"/>
<wire x1="6.65" y1="-11.6" x2="9.3" y2="-11.6" width="0.017" layer="23"/>
<wire x1="9.3" y1="-11.6" x2="9.3" y2="-5.65" width="0.017" layer="23"/>
<text x="1.27" y="-7.62" size="1.27" layer="21">&gt;NAME</text>
<text x="1.27" y="-10.16" size="1.27" layer="21">&gt;VALUE</text>
<hole x="2.35" y="-4.4" drill="1.8"/>
<hole x="2.35" y="-1.4" drill="1.8"/>
<hole x="10.35" y="-1.4" drill="1.8"/>
<hole x="9.35" y="-5" drill="1.1"/>
<hole x="1.85" y="-11.6" drill="1.1"/>
</package>
<package name="PRINTRELAIS-SCHRACK-PE-BISTABIL">
<pad name="P$1" x="1.4" y="1.4" drill="1.4"/>
<pad name="P$2" x="1.4" y="9" drill="1.4"/>
<pad name="P$3" x="11.6" y="9" drill="1.4"/>
<pad name="P$4" x="19.1" y="9" drill="1.4"/>
<pad name="P$5" x="19.1" y="1.4" drill="1.4"/>
<wire x1="2.5" y1="9" x2="4" y2="9" width="0.127" layer="48"/>
<wire x1="4" y1="9" x2="4" y2="6.5" width="0.127" layer="48"/>
<wire x1="4" y1="6.5" x2="2" y2="6.5" width="0.127" layer="48"/>
<wire x1="2" y1="6.5" x2="2" y2="4" width="0.127" layer="48"/>
<wire x1="4" y1="4" x2="6" y2="4" width="0.127" layer="48"/>
<wire x1="6" y1="4" x2="6" y2="6.5" width="0.127" layer="48"/>
<wire x1="4" y1="6.5" x2="6" y2="6.5" width="0.127" layer="48"/>
<wire x1="6" y1="6.5" x2="2" y2="4" width="0.127" layer="48"/>
<wire x1="2" y1="4" x2="4" y2="4" width="0.127" layer="48"/>
<wire x1="4" y1="4" x2="4" y2="1.5" width="0.127" layer="48"/>
<wire x1="4" y1="1.5" x2="2.5" y2="1.5" width="0.127" layer="48"/>
<wire x1="11.5" y1="8" x2="11.5" y2="5" width="0.127" layer="48"/>
<wire x1="11.5" y1="5" x2="15" y2="5" width="0.127" layer="48"/>
<wire x1="15" y1="5" x2="20" y2="3" width="0.127" layer="48"/>
<wire x1="19" y1="2.5" x2="19" y2="4" width="0.127" layer="48"/>
<wire x1="19" y1="8" x2="19" y2="6.5" width="0.127" layer="48"/>
<text x="3" y="9" size="1.27" layer="25">A1</text>
<text x="3" y="0" size="1.27" layer="25">A2</text>
<text x="12.5" y="9" size="1.27" layer="25">11</text>
<text x="16" y="9" size="1.27" layer="25">14</text>
<text x="16" y="0" size="1.27" layer="25">12</text>
<wire x1="-0.4" y1="10.4" x2="0" y2="10.8" width="0.127" layer="25" curve="-90"/>
<wire x1="0" y1="10.8" x2="20.4" y2="10.8" width="0.127" layer="25"/>
<wire x1="20.4" y1="10.8" x2="21" y2="10.2" width="0.127" layer="25" curve="-90"/>
<wire x1="21" y1="10.2" x2="21" y2="0.2" width="0.127" layer="25"/>
<wire x1="21" y1="0.2" x2="20.4" y2="-0.4" width="0.127" layer="25" curve="-90"/>
<wire x1="20.4" y1="-0.4" x2="0" y2="-0.4" width="0.127" layer="25"/>
<wire x1="0" y1="-0.4" x2="-0.4" y2="0" width="0.127" layer="25" curve="-90"/>
<wire x1="-0.4" y1="0" x2="-0.4" y2="10.4" width="0.127" layer="25"/>
</package>
</packages>
<symbols>
<symbol name="K">
<wire x1="-3.81" y1="-1.905" x2="-1.905" y2="-1.905" width="0.254" layer="94"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="1.905" width="0.254" layer="94"/>
<wire x1="3.81" y1="1.905" x2="1.905" y2="1.905" width="0.254" layer="94"/>
<wire x1="-3.81" y1="1.905" x2="-3.81" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="0" y1="-1.905" x2="3.81" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="94"/>
<wire x1="0" y1="1.905" x2="-3.81" y2="1.905" width="0.254" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="1.905" y2="1.905" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="0" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.905" y1="1.905" x2="0" y2="1.905" width="0.254" layer="94"/>
<text x="1.27" y="2.921" size="1.778" layer="96">&gt;VALUE</text>
<text x="1.27" y="5.08" size="1.778" layer="95">&gt;PART</text>
<pin name="2" x="0" y="-5.08" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="1" x="0" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
</symbol>
<symbol name="S">
<wire x1="0" y1="3.175" x2="0" y2="1.905" width="0.254" layer="94"/>
<wire x1="0" y1="-3.175" x2="0" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="-1.905" x2="-1.27" y2="1.905" width="0.254" layer="94"/>
<circle x="0" y="-1.905" radius="0.127" width="0.4064" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="95" rot="R90">&gt;PART</text>
<pin name="P" x="0" y="-5.08" visible="pad" length="short" direction="pas" swaplevel="1" rot="R90"/>
<pin name="S" x="0" y="5.08" visible="pad" length="short" direction="pas" swaplevel="1" rot="R270"/>
</symbol>
<symbol name="U">
<wire x1="3.175" y1="5.08" x2="1.905" y2="5.08" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.08" x2="-1.905" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="2.54" y2="5.715" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="0" y2="0" width="0.254" layer="94"/>
<circle x="0" y="1.27" radius="0.127" width="0.4064" layer="94"/>
<text x="2.54" y="0" size="1.778" layer="95">&gt;PART</text>
<pin name="O" x="5.08" y="5.08" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="S" x="-5.08" y="5.08" visible="pad" length="short" direction="pas"/>
<pin name="P" x="0" y="-2.54" visible="pad" length="short" direction="pas" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="AZ8-FORM-A" prefix="K">
<description>&lt;b&gt;MINIATURE PC BOARD RELAY&lt;/b&gt; Form A&lt;p&gt;
Source: www.azettler.com .. AZ8-1ch-12DSE.PDF</description>
<gates>
<gate name="K" symbol="K" x="0" y="0" addlevel="must"/>
<gate name="-1" symbol="S" x="17.78" y="0" addlevel="always"/>
</gates>
<devices>
<device name="" package="AZ8">
<connects>
<connect gate="-1" pin="P" pad="1"/>
<connect gate="-1" pin="S" pad="3"/>
<connect gate="K" pin="1" pad="2"/>
<connect gate="K" pin="2" pad="5"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TRS-1">
<description>TRS-1 12V Hochstromrelais

    Allgemeines
        Typ
        Automotive Powerrelais 
        Technologie
        monostabil 

    Ausführung
        Ausführung
        1x Wechsler 

    Anschlüsse / Schnittstellen
        Anschluss
        Printmontage 
        Kontakte
        AgSnO 

    Elektrische Werte
        Schaltleistung
        420 VA 
        Voltage DC
        12 V= 
        Innenwiderstand (Ri)
        253 Ohm 
        Nennstrom
        30 (16 V DC) A 
        Max. Schaltstrom
        30 A 
        Leistungsaufnahme (Betrieb)
        0,57 W 
        Prüfspannung
        500 V 

    Maße
        Länge
        13,2 mm 
        Breite
        12,3 mm 
        Höhe
        9,8 mm 

http://www.reichelt.de/index.html?&amp;ACTION=7&amp;LA=3&amp;OPEN=0&amp;INDEX=0&amp;FILENAME=C300%252FTRS.pdf</description>
<gates>
<gate name="G$1" symbol="K" x="-10.16" y="2.54"/>
<gate name="G$2" symbol="U" x="10.16" y="0"/>
</gates>
<devices>
<device name="" package="TSR-1-RELAIS">
<connects>
<connect gate="G$1" pin="1" pad="S1"/>
<connect gate="G$1" pin="2" pad="S2"/>
<connect gate="G$2" pin="O" pad="C"/>
<connect gate="G$2" pin="P" pad="P"/>
<connect gate="G$2" pin="S" pad="O"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="BISTABIL-SCHRACK" package="PRINTRELAIS-SCHRACK-PE-BISTABIL">
<connects>
<connect gate="G$1" pin="1" pad="P$1"/>
<connect gate="G$1" pin="2" pad="P$2"/>
<connect gate="G$2" pin="O" pad="P$3"/>
<connect gate="G$2" pin="P" pad="P$4"/>
<connect gate="G$2" pin="S" pad="P$5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X01">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" shape="octagon"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="PINHD1">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="-6.35" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="2.54" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X1" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X01">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="K1" library="0liver" deviceset="AZ8-FORM-A" device=""/>
<part name="U$1" library="0liver" deviceset="TRS-1" device="BISTABIL-SCHRACK"/>
<part name="JP1" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP2" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP3" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP4" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="JP5" library="pinhead" deviceset="PINHD-1X1" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="132.08" y1="53.34" x2="132.08" y2="50.8" width="0.1524" layer="97" style="shortdash"/>
</plain>
<instances>
<instance part="K1" gate="K" x="132.08" y="48.26" rot="R90"/>
<instance part="K1" gate="-1" x="144.78" y="45.72"/>
<instance part="U$1" gate="G$1" x="132.08" y="68.58" rot="R90"/>
<instance part="U$1" gate="G$2" x="152.4" y="68.58" rot="R90"/>
<instance part="JP1" gate="G$1" x="172.72" y="71.12"/>
<instance part="JP2" gate="G$1" x="172.72" y="63.5"/>
<instance part="JP3" gate="G$1" x="172.72" y="53.34"/>
<instance part="JP4" gate="G$1" x="172.72" y="45.72"/>
<instance part="JP5" gate="G$1" x="172.72" y="35.56"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="1"/>
<pinref part="K1" gate="K" pin="1"/>
<wire x1="127" y1="68.58" x2="127" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="2"/>
<pinref part="K1" gate="K" pin="2"/>
<wire x1="137.16" y1="68.58" x2="137.16" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="K1" gate="-1" pin="S"/>
<wire x1="144.78" y1="73.66" x2="144.78" y2="50.8" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$2" pin="O"/>
<wire x1="147.32" y1="73.66" x2="144.78" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$1" gate="G$2" pin="P"/>
<wire x1="154.94" y1="68.58" x2="154.94" y2="40.64" width="0.1524" layer="91"/>
<pinref part="K1" gate="-1" pin="P"/>
<wire x1="154.94" y1="40.64" x2="144.78" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
