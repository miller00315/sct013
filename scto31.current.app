<?xml version="1.0" encoding="ISO-8859-1" ?>

<app:application
    xmlns:app="http://embacados.contest.com/miller/application/1.0"
    type="mangoh.sct013.currentcloud.app"
    name="SCT013toCloud"
    revision="1.0">

	<application-manager use="LWM2M_SW"/>

	<capabilities>

		<encoding type="LWM2M">

			<asset default-label="MangOH Red" id="MangOH">

				<node path="Sensors" default-label="Sensors">

					<node path="Current" default-label="Current">
	      					<variable default-label="Level" path="Level" type="double" />
	    				</node>

					<node path="GPS" default-label="Gps">
              					<variable default-label="VerticalAccuracy" path="VerticalAccuracy" type="double" />
            				</node>

				</node>

			</asset>

		</encoding>

	</capabilities>


</app:application>
